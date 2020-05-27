
max = 0
rows = 4
cols = 4
square = [[0,0,0,1], [0,0,0,1], [0,0,0,1], [1,1,1,0]]
subsquare = [[-1 for i in range(len(square[0])+ 1)] for j in range(len(square)+ 1)]
def largestSquare(row,col):
   if row or col == 1 and square[row][col] == 0:
        subsquare[row][col] == 1
   elif row or col == 1 and square[row][col] != 0:
       subsquare[row][col] == 0

   else:
        if subsquare[row-1][col] and subsquare[row][col-1] and subsquare[row-1][col-1] >=0:
            subsquare[row][col] = min(subsquare[row-1][col], subsquare[row][col-1],subsquare[row-1][col-1]) + 1
        elif subsquare[row-1][col] and subsquare[row][col-1] >= 0:
            subsquare[row][col] = min(subsquare[row-1][col], subsquare[row][col-1],largestSquare(row-1,col-1)) + 1
        elif subsquare[row-1][col] and subsquare[row-1][col-1] >= 0:
            subsquare[row][col] = min(subsquare[row-1][col], largestSquare(row,col-1),subsquare[row-1][col-1]) + 1
        elif subsquare[row][col-1] and subsquare[row-1][col-1] >= 0:
            subsquare[row][col] = min(subsquare[row][col-1], largestSquare(row-1,col),subsquare[row-1][col-1]) + 1
        else:
            subsquare[row][col] = min(largestSquare(row,col-1), largestSquare(row-1,col),largestSquare(row-1,col-1)) + 1

   return subsquare[row][col]

for i in range(len(subsquare)):
    for j in range(len(subsquare[0])):
        if subsquare[i][j] > max:
            max = subsquare[i][j]
print(max)