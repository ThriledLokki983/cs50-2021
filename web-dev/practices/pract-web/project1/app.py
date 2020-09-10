from flask import Flask, render_template, url_for, flash, request, redirect
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_required, login_user, logout_user, current_user

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = True
app.config['SECRET_KEY'] = '123456'
db = SQLAlchemy(app)

login_manager = LoginManager()
login_manager.init_app(app)

class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    name = db.Column(db.String(45), nullable=False)
    username = db.Column(db.String(45), nullable=False)
    email = db.Column(db.String(60), nullable=False)
    password = db.Column(db.String(80), nullable=False)
    confirm = db.Column(db.String(80), nullable=False)

@login_manager.user_loader
def get(id):
    return User.query.get(id)

@app.route('/', methods=['GET'])
@login_required
def get_home():
    return render_template('index.html')

@app.route('/login', methods=['GET'])
def get_login():
    return render_template('login.html')

@app.route('/login', methods=['POST'])
def post_login():
    username = request.form['username']
    password = request.form['password']
    user = User.query.filter_by(username=username).first()
    login_user(user)
    return redirect('/')

@app.route('/register', methods=['GET'])
def get_register():
    return render_template('register.html')

@app.route('/register', methods=['POST'])
def post_register():
    name = request.form['name']
    username = request.form['username']
    email = request.form['email']
    password = request.form['password']
    confirm = request.form['confirm']
    new_user = User(name=name, username=username, email=email, password=password, confirm=confirm)
    db.session.add(new_user)
    db.session.commit()
    user = User.query.filter_by(email=email).first()
    login_user(user)
    return redirect('/')

@app.route('/logout', methods=['GET'])
def logout():
    logout_user(current_user)
    return redirect('/login')

  


if __name__ == "__main__":
 app.run(debug=True)



