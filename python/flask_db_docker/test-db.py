import sqlite3

db = sqlite3.connect('test.db')

cursor = db.cursor()

# cursor.execute("""
#     CREATE TABLE IF NOT EXISTS users (
#         id INTEGER PRIMARY KEY,
#         name VARCHAR(255)
#     )
# """)

# query = """
#     INSERT INTO users (id, name) VALUES (1, 'John Doe')
# """

another_query = """
    SELECT * FROM users
"""
cursor.execute(another_query)

data_from_db = cursor.fetchall()

print(data_from_db)


# cursor.execute(query)

# db.commit()
