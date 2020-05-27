Wmax = 6        #set Max weight of knapsack

#Open data file and store values in a matrix
infile = open("data.txt")
knapsack = []
for line in infile:
    knapsack.append([int(i) for i in line.split()])
knapsack = [i for i in knapsack if i]   #remove empty lines

B = [[0 for i in range(Wmax+1)] for j in range(len(knapsack)+1)]    #create matrix for bottom up approach
items = []  #create a list to store the used subset of items

for w in range(1, Wmax+1):
    for i in range(1,(len(knapsack)+1)):
        wi = knapsack[i-1][0]
        bi = knapsack[i-1][1]
        if wi <= w:
            if(bi +B[i-1][w - wi]) > B[i-1][w]:
                B[i][w] = bi +B[i-1][w - wi]

            else:
                B[i][w] = B[i-1][w]
                
        else:
            B[i][w] = B[i-1][w]
        
maxBenefit = B[-1][-1] #set max value

#find optimal subset
for i in range(len(knapsack)+1):
    indexVal = B[i][-1]
    if indexVal == maxBenefit:
        items.append(i-1)
        total = maxBenefit - knapsack[i-1][1]

for w in range(Wmax+1):
    for i in range((len(knapsack))+1):
        if B[i][w] == total:
            if i >0:
                items.append(i-1)
            total = total - knapsack[i-1][1]


#output Results to the screen

print("The optimal subset for a knapsack with a max weight of ", Wmax, " are items:")
for i in items:
    print("#", i)
print("for a Total value of $", maxBenefit)
infile.close()
for i in B:
    print(i)

    