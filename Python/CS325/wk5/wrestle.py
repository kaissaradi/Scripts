import math
import sys
#Split Teams function which takes a list of lists, each list being a rivlary or edge and a dictionary of players
# it then compares the players in each rivalry and updates their team or returns false if a team is not possible 
def splitTeams(rivalries, players):
    for pair in rivalries:
        team1 = players[pair[0]]
        team2 = players[pair[1]]
        #compare rivalries and update wrestlers teams in the dictionary
        if team1 == "None" and team2 == "None":
            players[pair[0]] = "Babyface"
            players[pair[1]] = "Heel"
        if team1 == "Babyface" and team2 == "None":
            players[pair[1]] = "Heel"
        if team1 == "Heel" and team2 == "None":
            players[pair[1]] = "Babyface"
        if team1 == "None" and team2 == "Babyface":
            players[pair[0]] = "Heel"  
        if team1 == "None" and team2 == "Heel":
            players[pair[0]] = "Babyface"  
        if team1 == team2 and team1 != "None":
            return 0    #return 0 if their is a conflict and two distinct teams cannot be made
    return 1

for argument in range(1,len(sys.argv)): #loop through each file given in the command line argument
    infile = open(str(sys.argv[argument]))    #open each file and read the lines into and array
    lines = infile.read().splitlines()
    numWreslters = int(lines[0])            
    verteces = {}  #dictionary to store each wreslter or vertex and their team
    for line in range(1,numWreslters + 1):
        verteces[lines[line]]= "None"  
    #create a list to store each rivalry or edge
    edges = []
    for line in range((numWreslters + 2), len(lines)):
        edges.append(lines[line].split()) #split each line into its key rivalry pairs

      
    #call function to sort the wreslters into teams if possible
    possible = splitTeams(edges, verteces)
    if not possible:
        print("No")
    else:
        print("Yes")
        babyfaces = []
        heels = []
        #store each player in apprpriate team, add to Babyface if no rivalries exist and print the output 
        for player in verteces:
            if verteces[player] == "Babyface" or verteces[player] == "None":
                babyfaces.append(player)
        for player in verteces:
            if verteces[player] == "Heel":
                heels.append(player)
        print("Babyfaces:", " ".join(babyfaces))
        print("Heels:", " ".join(heels))
    print("")
