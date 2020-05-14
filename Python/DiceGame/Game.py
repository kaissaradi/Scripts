import dice
import sys

class Game:
    def menu(self):
        print("Welcome to the Dice War Game:")
        selection = input("Please select an option:\n[1]Play Game\n[2]Exit\n")
        #validate input
        return selection
    def createDie(self):
        sideNum = input("\nHow many sides for the Die?:\n ")
        loaded = input("is the die loaded?\n[1]Yes\n[2]No\n")
        if loaded == 1:
            newDice = dice.loadedDie(sideNum)
        elif loaded == 2:
            newDice = dice.Dice(sideNum)
        return newDice
    #Play Function Runs the Game   
    def play(self):
        choice = self.menu()
        if choice == 1:
            #create dice
            print("\nPlease select a dice for Player 1:\n")
            player1Dice = self.createDie()
            print("\nPlease select a dice for Player 2:\n")
            player2Dice = self.createDie()
            #rounds
            rounds = input("How many rounds would you like to play?\n")
            P1score = 0
            P2score = 0
            #start game
            for i in range(rounds):
                i+=1
                #roll die
                roll1 = player1Dice.roll()
                roll2 = player2Dice.roll()
                #display details
                print("Round",i)
                print("Player 1's dice: " + player1Dice.type)
                print("Sides", player1Dice.getSides())
                print("Roll", roll1)
                print("Player 2's dice: " + player2Dice.type)
                print("Sides", player2Dice.getSides())
                print("Roll", roll2)
                #change score
                if roll1 > roll2:
                    P1score += 1
                    print("Player 1 wins this round!")
                elif roll2 > roll1:
                    P2score += 1
                    print("Player 2 wins this round!")
                elif roll1 == roll2:
                    print("Draw!")
                #end round, increment
                print("Current Score:",P1score,"to",P2score)
                print("\n")
            #End of game, print results
            print("Final Score: Player 1", P1score,"Player 2", P2score)
            if P1score > P2score:
                print("\n\nPlayer 1 Wins!")
            elif P2score > P1score:
                print("\n\nPlayer 2 Win!")
            else:
                print("Draw!")
        if choice == 2:
            #exit
            sys.exit()



