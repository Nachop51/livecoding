from flask import Flask, jsonify
from mysql.connector import connect

app = Flask(__name__)


@app.route('/', methods=['GET', 'POST'])
def home():
    return "Hola."


@app.route('/users', methods=['GET'])
def test():
    db = connect(
        host="db",
        port=3306,
        user="root",
        password="rooot",
        database="test"
    )
    cur = db.cursor()

    cur.execute("SELECT * FROM users")
    result = cur.fetchall()

    return jsonify(result)


@app.route('/users/<name>', methods=['POST'])
def create_user(name):
    db = connect(
        host="db",
        port=3306,
        user="root",
        password="rooot",
        database="test"
    )
    cur = db.cursor()

    cur.execute("INSERT INTO users (id, name) VALUES (NULL, %s)", (name,))

    db.commit()

    return jsonify(message="User created successfully")


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
