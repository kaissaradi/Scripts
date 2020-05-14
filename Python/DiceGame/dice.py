import random
class Dice(object):
    #Constructor, defaults to 6 sides
    def __init__(self, N = 6):
        self._sides = N
        self.type = "Not Loaded"
    #Roll functions returns randon number from 1 through sides
    def roll(self):
        return random.randint(1, self._sides)
    #setter
    def setSides(self, N):
        self._sides = N
    #Getter
    def getSides(self):
        return self._sides

class loadedDie(Dice):
    def __init__(self, N = 6):
        Dice.__init__(self, N)
        self.type = "Loaded"
    def roll(self):
        if self._sides == 1:
            return 1
        else:
            return random.randint((self._sides - 1), self._sides)