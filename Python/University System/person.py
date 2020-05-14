import random
class Person(object):
    def __init__(self, name = " ", age = random.randint(18, 65)):
        self._name = name
        self._age = age
    #getters
    def getName(self):
        return self._name
    def getAge(self):
        return self._age
    def doWork(self):   #name does X amount of work
        return 0
    def getScore(self): #return GPA or rating
        return 0

class Student(Person):
    def __init__(self, name, age, GPA = random.randint(0.0, 4.0)):
        Person.__init__(self, name, age)
        self._GPA = GPA
    def doWork(self):
        print(self._name, "Has done", random.randint(2, 40), "Hours of Homework")
    def getScore(self):
        return self._GPA
    
class Instructor(Person):
    def __init__(self, name, age, rating = random.randint(0.0, 5.0)):
        Person.__init__(self, name, age)
        self._rating = rating
    def doWork(self):
        print(self._name, "Has graded papers for", random.randint(1, 80), "Hours")
    def getScore(self):
        return self._rating

