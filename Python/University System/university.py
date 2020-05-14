import building
import person

def menu():       
    print("\n1. Print information about all the buildings on campus")
    print("2. Print information on everybody at the University")
    print("3. choose a person to work")
    print("4. Exit")
    choice = input("\n")
    return choice

class University():
    def __init__(self, name = " "):
        self._name = name
        self._buildings = []
        self._people = []
    def addBuilding(self, name, size, address):
        newBuilding = building.Building(name, size, address)
        self._buildings.append(newBuilding)
    def addPerson(self, type, name, age, rating):
        if type == 0:
            newPerson = person.Instructor(name, age, rating)
        if type == 1:
            newPerson = person.Student(name, age, rating)
        self._people.append(newPerson)
    def printBuildings(self):
        print("list of buildings:")
        listNum = 1
        for i in self._buildings:
            print("Building [%d] %s") % (listNum, i.getName())
            print("         Size: %d sqft   %s") % (i.getSize(), i.getAddress())
            listNum += 1
    def printPeople(self):
        print("List of students and faculty:")
        listNum = 1
        for i in self._people:
            print(listNum, i.getName(), "Age", i.getAge(), "GPA/Rating", i.getScore())
            listNum += 1
    #Getters for person list 
    def  getPerson(self, choice):
        return self._people[choice]
