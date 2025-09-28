from flask import Flask, render_template, request, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
import subprocess

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class Activity(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(50), nullable=False)
    day = db.Column(db.String(10), nullable=False)
    start_time = db.Column(db.String(5), nullable=False)
    end_time = db.Column(db.String(5), nullable=False)
    priority = db.Column(db.Integer, default=1)

@app.route("/")
def home():
    activities = Activity.query.all()
    return render_template("index.html", activities=activities)

@app.route("/add", methods=["POST"])
def add():
    name = request.form['name']
    day = request.form['day']
    start_time = request.form['start_time']
    end_time = request.form['end_time']
    priority = request.form['priority']

    new_activity = Activity(
        name=name, day=day, start_time=start_time,
        end_time=end_time, priority=priority
    )
    db.session.add(new_activity)
    db.session.commit()

    # redirect to game if free time
    if name.strip().lower() in ["free", "free time", "休み"]:
        return redirect(url_for("free_time_game"))

    activities = Activity.query.all()
    return render_template("index.html", activities=activities)

@app.route("/delete/<int:id>", methods=["POST"])
def delete_activity(id):
    activity = Activity.query.get_or_404(id)
    db.session.delete(activity)
    db.session.commit()
    return redirect("/")

@app.route("/free_time_game")
def free_time_game():
    result = subprocess.run(["./battle"], capture_output=True, text=True)
    game_result = result.stdout
    return render_template("game.html", game_result=game_result)

@app.route("/c_mode_game")
def c_mode_game():
    result=subprocess.run(["./battle"],capture_output=True,text=True)
    game_result=result.stdout
    return render_template("game.html", game_result=game_result)

@app.route("/mini_maze")
def mini_maze():
    return render_template("mini_maze.html")

if __name__ == "__main__":
    with app.app_context():
        db.create_all()
    app.run(debug=True)
