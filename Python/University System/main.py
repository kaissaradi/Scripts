import building
import person
import university

uni = "Oregon STate University"
OSU = university.University(uni)
 
OSU.addBuilding("Milam Hall [Mlm]",8000,"2520 SW Campus Way")
OSU.addBuilding("Memorial Union [MU]",20000,"2501 SW Jefferson Way")
OSU.addBuilding("Valley Library [VLib]",80000,"201 SW Waldo Place")

OSU.addPerson(0, "Elon Musk", 42, 4.5)
OSU.addPerson(0, "Jerry Seinfeld", 55, 2.2)
OSU.addPerson(1, "Kais Saradi", 23, 3.5)
OSU.addPerson(1,"Jim Marbury", 32, 4.0)

print("Welcome to the OSU information Menu, Please make a selection:")

choice = university.menu()
while choice != 4:
    if choice == 1:
        OSU.printBuildings()
        print("Returning to menu\n")
    if choice == 2:
        OSU.printPeople()
        print("Returning to menu\n")
    if choice == 3:
        OSU.printPeople()
        choice = input("Please select a person to do work\n")
        choice -= 1
        person = OSU.getPerson(choice)
        person.doWork()
    if choice == 4:
        break
    choice = university.menu()
        