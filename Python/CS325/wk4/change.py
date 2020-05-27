import math
#makechange function stores results in an array and returns it
def makeChange(c,k,n):
    results = []
    #set Kmax
    if math.log(n,(c)) < k:
            k = int(math.log(n,(c)))
    while n > 0:               #find number of coins for each demonination and store results
        demoniation = c**k
        if n / c**k >= 1:
            numCoins = n // demoniation
            n %=  demoniation
            results.append(demoniation)
            results.append(numCoins)
        k -= 1
    return results
#open input and output files
infile = open("data.txt")
outfile = open("change.txt","w")
array = []  #array to store inputs from data.txt
newArr = [] #array to hold results to be written to change.txt

for line in infile:         #store store values from input file in array
    array.append([int(i) for i in line.split()])
array = [i for i in array if i]   #remove empty lines

for list in array:          #call make change function for each line in array
    newArr.append(makeChange(list[0],list[1],list[2]))

for list in newArr:         #write results in from newArr in output file
    for item in range(0,len(list)-1,2):
        outfile.write("%d" % list[item])
        outfile.write(" ")
        outfile.write("%d" % list[item+1])
        outfile.write("\n")
    #add delimiter to seperate multiple lines of input
    if list == newArr[-1]:
        continue
    else:
        outfile.write("--------------\n")
outfile.write("\n")
#close txt files 
infile.close()
outfile.close()