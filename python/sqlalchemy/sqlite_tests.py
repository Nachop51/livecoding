import sqlite3

con = sqlite3.connect('test.db')

cursor = con.cursor()

# query = """
#     CREATE TABLE laptops (
#         student_id INT,
#         cohort_id INT,
#         FOREIGN KEY (student_id) REFERENCES students(id),
#         FOREIGN KEY (cohort_id) REFERENCES cohorts(id)
#     );
# """

# cursor.execute(query)

# con.commit()

# query = """
#     CREATE TABLE students (
#         id INT PRIMARY KEY,
#         cohort_id INT,
#         name VARCHAR(256),
#         FOREIGN KEY (cohort_id) REFERENCES cohorts(id)
#     );
# """

# query = """
#     INSERT INTO students (id, cohort_id, name)
#     VALUES (6338, 20, 'Emilio');
# """

# query = """
#     SELECT s.id, s.name, c.name
#     FROM students AS s
#     JOIN cohorts AS c ON s.cohort_id = c.id
# """

# query = """
#     INSERT INTO laptops (student_id, cohort_id, number)
#     VALUES (6334, 20, 'H23');
# """

# cursor.execute("ALTER TABLE laptops ADD COLUMN number VARCHAR(256)")

# query = """
#     SELECT s.id, s.name, c.name, l.number
#     FROM students AS s
#     JOIN cohorts AS c ON s.cohort_id = c.id
#     JOIN laptops AS l ON s.id = l.student_id
#     WHERE c.id = 19;
# """

query = """
    SELECT c.name, l.number
    FROM cohorts AS c
    JOIN laptops AS l ON c.id = l.cohort_id
    WHERE c.id = 19;
"""

cursor.execute(query)

# con.commit()

fetched = cursor.fetchall()

for row in fetched:
    print(row)
