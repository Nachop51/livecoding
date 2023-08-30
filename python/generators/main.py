
# def return_n_times(n):
#     for i in range(n):
#         yield i


# generator = return_n_times(10)

# print(generator)

# for obj in generator:
#     print(obj)

from timeit import timeit


def map_approach():
    people: list[str] = ["John", "Mary", "Peter", "George", "Anna"]
    new_people = map(str.upper, people)

    return new_people


def list_approach():
    people: list[str] = ["John", "Mary", "Peter", "George", "Anna"]
    new_people = [person.upper() for person in people]

    return new_people


print(timeit(map_approach, number=100000))
print(timeit(list_approach, number=100000))
