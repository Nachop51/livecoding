from flask import Flask, jsonify
import sqlite3
from random import randint
# query = """
#     CREATE TABLE student
#     (id INT, name VARCHAR(256))
# """
# query = """
#     INSERT INTO student (id, name)
#     VALUES (10, 'Nacho'), (50, 'Ivan')
# """
# cur.execute(query)
# con.commit()
app = Flask(__name__)


@app.route("/")
def home():
    return "Pagina principal"


@app.route("/<name>")
def greet(name):
    return f"Hola {name}"


@app.route("/<int:n>/<int:n2>")
def sum(n, n2):
    return str(n + n2)


@app.route("/students")
def students():
    query = """
        SELECT * FROM student
    """
    con = sqlite3.connect("holberton.db")

    cur = con.cursor()
    cur.execute(query)
    fetched = cur.fetchall()
    print(fetched)
    return jsonify(fetched)


@app.route("/create_student/<name>")
def create(name):
    con = sqlite3.connect("holberton.db")

    cur = con.cursor()
    query = """
			INSERT INTO student (id, name)
			VALUES (%s, '%s')
		"""
    cur.execute(query % (randint(100, 1000), name))
    con.commit()
    return jsonify("Student created")


if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000, debug=True)
