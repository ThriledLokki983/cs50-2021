import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd, validate

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached


@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/admin", methods=["GET"])
def admin():
    rows = db.execute("""
        SELECT id, username, hash, cash
        FROM users;
    """)
    holdings = []
    for row in rows:
        holdings.append({
            "id": row["id"],
            "user": row["username"],
            "hash": row["hash"],
            "cash": row["cash"]
        })
    return render_template("admin.html", holdings=holdings)


@app.route("/")
@login_required
def index():

    # Query to get sum of all Shares for each Stock(symbol) we have bought so far
    rows = db.execute("""
        SELECT symbol, SUM(shares) as Total_Shares 
        FROM transactions 
        WHERE user_id= :user_id
        GROUP BY symbol 
        HAVING Total_Shares > 0;
    """, user_id=session["user_id"])

    # The query returns a dictionary of value pairs
    holdings = []
    grand_total = 0
    for row in rows:
        stock = lookup(row["symbol"])
        holdings.append({
            "symbol": stock["symbol"],
            "name": stock["name"],
            "shares": row["Total_Shares"],
            "price": usd(stock["price"]),
            "total": usd(stock["price"] * row["Total_Shares"])
        })

        # An object which takes into account our total cash into consideration
        grand_total += stock["price"] * row["Total_Shares"]

    # Query from the users database which user's information(cash) to show
    rows = db.execute("SELECT cash FROM users WHERE id=:user_id",
                      user_id=session["user_id"])
    cash = rows[0]["cash"]
    grand_total += cash
    return render_template("index.html", holdings=holdings, cash=cash, grand_total=grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == 'POST':
        if not request.form.get("symbol"):
            return apology("Please enter the Symbol to buy:")
        if not request.form.get("shares"):
            return apology("Please enter the shares you want to buy:")
        if not request.form.get("shares").isdigit():
            return apology("Invalid Number of Share")
        symbol = request.form.get("symbol").upper()
        stock = lookup(symbol)
        shares = int(request.form.get("shares"))
        if stock is None:
            return apology("Invalid Symbol")
        rows = db.execute(
            "SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = rows[0]["cash"]
        update_cash = cash - shares * stock["price"]
        if update_cash < 0:
            return apology("You are low on Cash")
        db.execute("UPDATE users SET cash=:update_cash WHERE id=:id",
                   update_cash=update_cash,
                   id=session["user_id"])
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES(:user_id, :symbol, :shares, :price)",
                   user_id=session["user_id"],
                   symbol=stock["symbol"],
                   shares=shares,
                   price=stock["price"])
        flash("Successful Transaction")
        return redirect("/")
    else:
        return render_template('buy.html')


@app.route("/cash", methods=["GET", "POST"])
@login_required
def cash():
    """ When User clicks on the Add Cash Button """
    if request.method == "POST":
        cash = request.form.get("addCash")
        cash_remaining = db.execute(
            "SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        total_cash = int(cash) + cash_remaining[0]["cash"]
        db.execute("UPDATE users SET cash=:total_cash WHERE id=:id",
                   total_cash=total_cash, id=session["user_id"])
        flash("You have Successfully added more cash")
        return redirect(url_for("index"))
    return render_template("cash.html")


@app.route("/history", methods=["GET", "POST"])
@login_required
def history():
    transactions = db.execute("""
            SELECT symbol, shares, price, transacted 
            FROM transactions
            WHERE user_id =:user_id
        """, user_id=session["user_id"])
    holdings = []
    for trans in transactions:
        stock = lookup(trans["symbol"])
        holdings.append({
            "symbol": stock["symbol"],
            "name": stock["name"],
            "shares": trans["shares"],
            "price": usd(stock["price"]),
            "transacted": trans["transacted"]
        })
    """Show history of transactions"""
    return render_template("history.html", transactions=holdings)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Unknown Symbol", 400)
        symbol1 = request.form.get("symbol")
        symbol = symbol1.upper()
        stock = lookup(symbol)
        if stock is None:
            return apology("Invalid Symbol", 400)
        return render_template("quoted.html", stock=stock)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == 'POST':
        if not request.form.get('username'):
            return apology("Please provide a unique username", 403)
        if not request.form.get('password'):
            return apology("Please Provide a password", 403)
        if not request.form.get('confirmation'):
            return apology("Please confirm password", 403)
        validate_error = validate(request.form.get("password"))
        if validate_error:
            return validate_error
        if request.form.get('password') != request.form.get('confirmation'):
            return apology("Password do not match", 403)
        user = db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)",
                          username=request.form.get('username'),
                          hash=generate_password_hash(request.form.get('password')))
        if user is None:
            return apology("Unsuccessful Registration", 403)
        flash("Lets Start TRADING !!!")
        session['user_id'] = user
        return redirect("/")
    else:
        return render_template('register.html')


@app.route("/sell", methods=["GET", "POST"])
@login_required
#    """Sell shares of stock"""
def sell():
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Please enter the Symbol to buy:")
        if not request.form.get("shares"):
            return apology("Please enter the shares you want to buy:")
        if not request.form.get("shares").isdigit():
            return apology("Invalid Number of Share")
        symbol = request.form.get("symbol").upper()
        stock = lookup(symbol)
        shares = int(request.form.get("shares"))
        if stock is None:
            return apology("Invalid Symbol")
        rows = db.execute("""
            SELECT symbol, SUM(shares) as totalShares
            FROM transactions
            WHERE user_id=:user_id
            GROUP BY symbol
            HAVING totalShares > 0;
        """, user_id=session["user_id"])
        for row in rows:
            if row["symbol"] == symbol:
                if shares > row["totalShares"]:
                    return apology("Too many Shares")

        rows = db.execute(
            "SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = rows[0]["cash"]

        updated_cash = cash + shares * stock["price"]
        db.execute("UPDATE users SET cash=:updated_cash WHERE id=:id",
                   updated_cash=updated_cash,
                   id=session["user_id"])
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES(:user_id, :symbol, :shares, :price)",
                   user_id=session["user_id"],
                   symbol=stock["symbol"],
                   shares=-1 * shares,
                   price=stock["price"])
        flash("Successful Transaction")
        return redirect("/")
    else:
        rows = db.execute("""
            SELECT symbol
            FROM transactions
            WHERE user_id=:user_id
            GROUP BY symbol
            HAVING SUM(shares) > 0;
        """, user_id=session["user_id"])
        return render_template("sell.html", symbols=[row["symbol"] for row in rows])


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
