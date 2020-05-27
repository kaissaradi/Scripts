rows = 5
cols = 5
board = [[0 for i in range(cols+1)] for j in range(rows+1)]

def shortestpath(row, col):
    if row == 1 or col == 1:
        board[row][col] = 1
    elif row >= 1 and col >=1:
        if board[row-1][col] != 0 and board[row][col-1]  != 0:
            board[row][col] = board[row-1][col] + board[row][col-1]
        elif board[row-1][col] != 0:
            board[row][col] = board[row-1][col] + shortestpath(row,col-1)
        elif board[row][col-1] != 0:
            board[row][col] = board[row][col-1] + shortestpath(row-1,col)
        else:
            board[row][col] = shortestpath(row-1,col)+shortestpath(row,col-1)
    return board[row][col]

shortestRowsanCols = shortestpath(rows,cols)

print(shortestRowsanCols)
for i in range(1,rows+1):
    print(board[i])
