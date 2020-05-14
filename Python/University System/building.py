class Building(object):
    def __init__(self, name = "Empty Building", size = 0.0, address = " "):
        self._name = name
        self._size = size
        self._address = address
    #setters
    def setName(self, name):
        self._name = name
    def setSize(self, size):
        self._size = size
    def setAddress(self, address):
        self._address = address   
    #getters
    def getName(self):
        return self._name
    def getSize(self):
        return self._size
    def getAddress(self):
        return self._address
    