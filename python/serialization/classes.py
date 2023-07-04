# class MyClass:
#     def __init__(self, a, b):
#         self.a = a
#         self.b = b

#     @staticmethod
#     def add(a, b):
#         return a + b

#     def add_not_static(self, a, b=1):
#         return a + b

# print('Add from MyClass', MyClass.add(10, 5))
# obj = MyClass(10, 5)
# print('Add from obj', obj.add(10, 5))
# print('add_not_static from obj', obj.add_not_static(10, 5))

class Parent:
    def __init__(self):
        pass

    @classmethod
    def greet(cls):
        print(f'Hello {cls.__name__}!')
        return cls()

class Child1(Parent):
    def __init__(self):
        pass

class Child2(Parent):
    def __init__(self):
        pass

# child1 = Child1()
# child2 = Child2()

child = Child1.greet()
child = Child2.greet()
