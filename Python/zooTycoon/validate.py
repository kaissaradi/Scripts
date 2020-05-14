import sys
def checkInt():
   while True:
    try:
        num = input("Please enter an integer: ")
    except SyntaxError:
        print("\nError!")
        continue
    else:
        #num was successfully parsed!
        #we're ready to exit the loop.
        if isinstance(num, int):
            return num
        else: continue

def validateInt(lowerLimit = 0, upperlimit = sys.maxsize ):
    print("enter and integer between %d and %d") % (lowerLimit, upperlimit)
    num = lowerLimit - 1
    while num < lowerLimit or num > upperlimit:
        num = checkInt()
    return num