from flask import Flask, render_template, url_for, request, redirect, flash
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime 
from flask_login import LoginManager, UserMixin, login_required, login_user, logout_user, current_user


app = Flask(__name__)
app.config['FLASK_DEBUG'] = True
app.config['SECRET_KEY'] = "ogidi@12"
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = True
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///posts.db'
db = SQLAlchemy(app)

login_manager = LoginManager()
login_manager.init_app(app)

class BlogPost(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(80), nullable=False)
    content = db.Column(db.Text, nullable=False)
    author = db.Column(db.String(48), nullable=False, default='N/A')
    date = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)

    def __repr__(self):
        return 'Blog Post ' + str(self.id)


class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(80), nullable=False)
    username = db.Column(db.String(80), nullable=False)
    email = db.Column(db.String(80), nullable=False)
    password = db.Column(db.String(80), nullable=False)
    confirm = db.Column(db.String(80), nullable=False)

@login_manager.user_loader
def get_id():
    return User.query.get(id)

@app.route('/', methods=['GET'])
@login_required
def index():
    return render_template('index.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()
        login_user(user)
        return redirect(url_for('/'))
    else:
        return render_template('login.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        name = request.form['name']
        username = request.form['username']
        email = request.form['email']
        password = request.form['password']
        confirm = request.form['confirm']
        new_user = User(name=name, username=username, email=email, password=password, confirm=confirm)
        db.session.add(new_user)
        db.session.commit()
        user = User.query.filter_by(username=username).first()
        if password != confirm:
            return render_template('error.html')
        else:
            login_user(user)
            return redirect('/')
    else:
        return render_template('register.html')

@app.route('/logout', methods=['GET'])
def logout():
    logout_user(current_user)
    return redirect('/')


@app.route('/post', methods=['GET', 'POST'])
def post():
    if request.method == 'POST':
        post_title = request.form['title']
        post_content = request.form['content']
        post_author = request.form['author']
        new_post = BlogPost(title=post_title, author=post_author, content=post_content)
        db.session.add(new_post)
        db.session.commit()
        return redirect('/post')
    else:
        all_post = BlogPost.query.order_by(BlogPost.date).all()
        return render_template('post.html', posting=all_post)

@app.route('/post/delete/<int:id>')
def delete(id):
    posts = BlogPost.query.get_or_404(id)
    db.session.delete(posts)
    db.session.commit()
    return redirect('/post')


@app.route('/post/edit/<int:id>', methods=['GET', 'POST'])
def edit(id):
    posts = BlogPost.query.get_or_404(id)

    if request.method == 'POST':
        posts.title = request.form['title']
        posts.content = request.form['content']
        posts.author = request.form['author']
        db.session.commit()
        return redirect('/post')
    else:
        return render_template('edit.html', post=posts)


@app.route('/post/new', methods=['GET', 'POST'])
def newpost():
    if request.method == 'POST':
        post_title = request.form['title']
        post_content = request.form['content']
        post_author = request.form['author']
        new_post = BlogPost(title=post_title, author=post_author, content=post_content)
        db.session.add(new_post)
        db.session.commit()
        return redirect('/post')
    else:
        return render_template('/newpost.html')

if __name__ == "__main__":
    app.run(debug=True)