#souce https://www.geeksforgeeks.org/python-linear-programming-in-pulp/
# import the library pulp as p 
import pulp as p 
  
# Create problem Variables  
bin1 = p.LpVariable("bin1", 0, 10)
bin2 = p.LpVariable("bin2",0, 10)
bin3 = p.LpVariable("bin3",0, 10)
bin4 = p.LpVariable("bin4",0,10)
bin5 = p.LpVariable("bin5",0,10)
bin6 = p.LpVariable("bin6",0,10)

Y1 = p.LpVariable("Y1",0,1)
Y2 = p.LpVariable("Y2",0,1)
Y3 = p.LpVariable("Y3",0,1)
Y4 = p.LpVariable("Y4",0,1)
Y5 = p.LpVariable("Y5",0,1)
Y6 = p.LpVariable("Y6",0,1)

X11 = p.LpVariable("X1-1",0,1)
X12 = p.LpVariable("X1-2",0,1)
X13 = p.LpVariable("X1-3",0,1)
X14 = p.LpVariable("X1-4",0,1)
X15 = p.LpVariable("X1-5",0,1)
X16 = p.LpVariable("X1-6",0,1)

X21 = p.LpVariable("X2-1",0,1)
X22 = p.LpVariable("X2-2",0,1)
X23 = p.LpVariable("X2-3",0,1)
X24 = p.LpVariable("X2-4",0,1)
X25 = p.LpVariable("X2-5",0,1)
X26 = p.LpVariable("X2-6",0,1)

X31 = p.LpVariable("X3-1",0,1)
X32 = p.LpVariable("X3-2",0,1)
X33 = p.LpVariable("X3-3",0,1)
X34 = p.LpVariable("X3-4",0,1)
X35 = p.LpVariable("X3-5",0,1)
X36 = p.LpVariable("X3-6",0,1)

X41 = p.LpVariable("X1-1",0,1)
X42 = p.LpVariable("X1-2",0,1)
X43 = p.LpVariable("X1-3",0,1)
X44 = p.LpVariable("X1-4",0,1)
X45 = p.LpVariable("X1-5",0,1)
X46 = p.LpVariable("X1-6",0,1)

X51 = p.LpVariable("X5-1",0,1)
X52 = p.LpVariable("X5-2",0,1)
X53 = p.LpVariable("X5-3",0,1)
X54 = p.LpVariable("X5-4",0,1)
X55 = p.LpVariable("X5-5",0,1)
X56 = p.LpVariable("X5-6",0,1)

X61 = p.LpVariable("X6-1",0,1)
X62 = p.LpVariable("X6-2",0,1)
X63 = p.LpVariable("X6-3",0,1)
X64 = p.LpVariable("X6-4",0,1)
X65 = p.LpVariable("X6-5",0,1)
X66 = p.LpVariable("X6-6",0,1)

variables = [bin1, bin2, bin3, bin4, bin5, bin6, Y1, Y2, Y3, Y4, Y5, Y6, X11, X12, X13, X14, X15, X16, X21, X22, X23, X24, X25, X26, X31, X32, X33, X34, X35, X36, X41, X42, X43, X44, X45, X46, X51, X52, X53, X54, X55, X56, X61, X62, X63, X64, X65, X66] 

# Create a LP Minimization problem 
problem = p.LpProblem("Bin-Packing-Problem", p.LpMinimize)

# Objective Function ,
problem += Y1 + Y2 + Y4 + Y5 + Y6 
# Constraints: 
problem += X11 + X12 + X13 + X14 + X15 + X16 <= 1
problem += X21 + X22 + X23 + X24 + X25 + X26 <= 1
problem += X31 + X32 + X33 + X34 + X35 + X36 <= 1
problem += X41 + X42 + X43 + X44 + X45 + X46 <= 1
problem += X51 + X52 + X53 + X54 + X55 + X56 <= 1
problem += X61 + X62 + X63 + X64 + X65 + X66 <= 1

problem += (4*X11) + (4*X21) + (4*X31) + (6*X41) + (6*X51) + (6*X61) <= (10*Y1)
problem += (4*X12) + (4*X22) + (4*X32) + (6*X42) + (6*X52) + (6*X62) <= (10*Y2)
problem += (4*X13) + (4*X23) + (4*X33) + (6*X43) + (6*X53) + (6*X63) <= (10*Y3)
problem += (4*X14) + (4*X24) + (4*X34) + (6*X44) + (6*X54) + (6*X64) <= (10*Y4)
problem += (4*X15) + (4*X25) + (4*X35) + (6*X45) + (6*X55) + (6*X65) <= (10*Y5)
problem += (4*X16) + (4*X26) + (4*X36) + (6*X46) + (6*X56) + (6*X66) <= (10*Y6)


# Display the problem 
print(problem) 
#solve and print solution
solution = problem.solve()
print("\n SOLUTION STATUS:  ", p.LpStatus[solution])   
# Print the object value and variables
print("\nOBJECTIVE VALUE:   ", p.value(problem.objective))
for i in range(4):   
    print("VARIABLE:", p.LpVariable.getName(variables[i])," VALUE:", p.value(variables[i]))
