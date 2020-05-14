from validate import checkInt
import random
from validate import validateInt
import animal

class Zoo(object):
    def __init__(self):
        self._profit = 0
        self._balance = 100000
        self._tigerCage = []
        self._penguinCage = []
        self._turtleCage = []
    #add functions
    def addAnimal(self, cage, animalType):
        if animalType == 0:
            newAnimal = animal.Tiger()
        if animalType == 1:
            newAnimal = animal.Turtle()
        if animalType == 2:
            newAnimal = animal.Penguin()
        cage.append(newAnimal)
    def addTurtle(self):
        newTurtle = animal.Turtle()
        cage.append(newTurtle)
    def addPenguin(self):
        newPenguin = animal.Penguin()
        cage.append(newPenguin)
    #Remove Functions - return false if cage is empty
    def removeAnimal(self, cage, animalName):
        if(len(cage) == 0):
            return False
        else:
            cage.pop(len(cage - 1))
            print("A %s has been Removed from the Zoo") % (animalName)
            return True
    def removeTurtle(self):
        if(len(self._turtleCage) == 0):
            return False
        else:
            self._turtleCage.pop(len(self._turtleCage - 1))
            print("A Turtle has been Removed from the Zoo")
            return True
    def removePenguin(self):
        if(len(self._penguinCage) == 0):
            return False
        else:
            self._penguinCage.pop(len(self._penguinCage - 1))
            print("A Penguin has been Removed from the Zoo")
            return True
    #random function
    def RandomDeath(self):
        animalsRem = False
        randAnimal = random.randrange(0,4,1)
        if(randAnimal == 1):
            animalsRem = self.removeTiger()
            if not animalsRem:
                animalsRem = self.removeTurtle()
            if not animalsRem:
                animalsRem = self.removePenguin()
        if(randAnimal == 2):
            animalsRem = self.removeTurtle()
            if not animalsRem:
                animalsRem = self.removeTiger()
            if not animalsRem:
                animalsRem = self.removePenguin()
        if(randAnimal == 3):
            animalsRem = self.removePenguin()
            if not animalsRem:
                animalsRem = self.removeTurtle()
            if not animalsRem:
                animalsRem = self.removeTiger()
        else:
            print("There Are no more animals left in the Zoo")
    #functions to check for adults
    def hasAdult(self, cage):
        for i in cage:
            if(i.getAge()> 2):
                return True
            else:
                return False
    def hasAdultTurtle(self):
        for i in self._turtleCage:
            if(i.getAge()> 2):
                return True
            else:
                return 
    def hasAdultPenguin(self):
        for i in self._penguinCage:
            if(i.getAge()> 2):
                return True
            else:
                return False
    def calcProfit(self):
        for i in self._tigerCage:
            self._profit += i.getpayoff()
        for i in self._turtleCage:
            self._profit += i.getpayoff()
        for i in self._penguinCage:
            self._profit += i.getpayoff()
    def changeDay(self):
        for i in self._tigerCage:
            i.incAge()
        for i in self._turtleCage:
            i.incAge()
        for i in self._penguinCage:
            i.incAge()
    def RandomEvent(self):
        ranEvent = random.randrange(1,4,1)
        tiger_COST = 10000
        penguin_COST = 1000
        turtule_COST = 100
        BASE_FOOD_COST = 10
        if ranEvent == 1
            print("Random Event: A sickness occurs, an animal is removed from the zoo.")
            self.RandomDeath()
        elif ranEvent == 2:
            print("Random Event: A boom in zoo attendance occurs.")
            for i in self._tigerCage:
                randBonus = random.randrange(250, 500, 1)
                i.setPayoff(i.getpayoff() + randBonus)
            print("A bonus of %d has been added for each tiger in the zoo") % (randBonus)
        elif ranEvent == 3:
            print("Random Event: A baby is born!")
            babyType = random.randrange(1, 3, 1)
            if babyType == 1 && self.hasAdult(self._tigerCage):
                for i in range(animal.Tiger.getNumBabies()):
                    self.addAnimal(self._tigerCage, 0)
                print("A Tiger Cub was Born!")
            if babyType == 2 && self.hasAdult(self._penguinCage):
                for i in range(animal.Penguin.getNumBabies()):
                    self.addAnimal(self._penguinCage, 2)
                print("5 Peguin chicks were hatched!")
            if babyType == 3 && self.hasAdult(self._turtleCage):
                for i in range(animal.Turtle.getNumBabies()):
                    self.addAnimal(self._turtleCage, 1) 
                print("10 Turtle Eggs were hatched!")       
        elif ranEvent == 4:
            print("Random Event: Nothing happened")  
    #getters
    def getProfit(self):
        return self._profit 
    def getBalance(self):
        return self._balance
    def getTigerExhib(self):
        return self._tigerCage
    def getTurtleExhib(self):
        return self._turtleCage
    def getPenguinExhib(self):
        return self._penguinCage
    def getAnimalCount(self, cage):
        return len(cage)
    #setters
    def setProfit(self, profit):
        self._profit = profit
    def setBalance(self, balance):
        self._balace = balance
