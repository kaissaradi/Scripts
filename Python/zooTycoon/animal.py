baseFoodCost = 10   #Base food Cost
#Animal parent class
class Animal(object):
    def __init__(self, age = 0):
        self._age = age
        self._cost = 0
        self._numBabies = 0
        self._FoodCost = baseFoodCost
        self._payoff = 0
    #Function to increment age by one day
    def incAge(self):
        self._age += 1
    #Getters
    def getAge(self):
        return self._age
    def getCost(self):
        return self._cost
    def getNumBabies(self):
        return self._numBabies
    def getFoodCost(self):
        return self._FoodCost
    def getPayoff(self):
        return self._payoff
    #Setters
    def setPayoff(self, payoff):
        self._payoff = payoff
#Sub Classes
class Tiger(Animal):
    def __init__(self, age = 0):
        self._age = age
        self._cost = 10000
        self._numBabies = 1
        self._FoodCost = 5 * baseFoodCost
        self._payoff = 0.2 * self._cost

class Penguin(Animal):
    def __init__(self, age = 0):
        self._age = 0
        self._cost = 1000
        self._numBabies = 5
        self._payoff = 0.1 * self._cost

class Turtle(Animal):
    def __init__(self, age = 0):
        self._age = 0
        self._cost = 100
        self._numBabies = 10
        self._FoodCost = 0.5 * baseFoodCost
        self._payoff = 0.05 * self._cost