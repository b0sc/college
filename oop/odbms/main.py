import shelve

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

# Storing objects in the database
with shelve.open("mydatabase") as db:
    person1 = Person("Alice", 30)
    person2 = Person("Bob", 25)
    db["alice"] = person1
    db["bob"] = person2

# Retrieving objects from the database
with shelve.open("mydatabase") as db:
    retrieved_person = db["alice"]
    print(f"Name: {retrieved_person.name}, Age: {retrieved_person.age}")