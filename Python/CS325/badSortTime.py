from fractions import Fraction
from random import randrange
import time

def badSort(arrayObj,start, end, alpha):
    start_T = time.time()
    size = (end - start)
    if size == 2 and arrayObj[start] > arrayObj[start+1]:
        arrayObj[start], arrayObj[start+1] = arrayObj[start+1], arrayObj[start]
    elif size > 2:
        if arrayObj[end-1] < arrayObj[start+1]:
            arrayObj[start+1], arrayObj[end-1] = arrayObj[end-1], arrayObj[start+1]
        if arrayObj[start] > arrayObj[start+1]:
            arrayObj[start], arrayObj[start+1] = arrayObj[start+1], arrayObj[start]
        if(size%2 == 0):
            m = round(alpha * size)
        else:
            m = int(alpha * size)
        i = size - m
        badSort(arrayObj,start, m, alpha)
        badSort(arrayObj,(start+i), end, alpha)
        badSort(arrayObj,start, m, alpha)
    end_T = time.time()
    return (end_T - start_T)

array = []
a = input("Please enter a fraction between 1/2 and 1 for the value of alpha\n")
a = float(Fraction(a))
n = int(input("Please enter a value of N for the array\n"))
for i in range(n):
    array.append(randrange(0, 10001))
algTime = badSort(array, 0 , n, a)
print("Time", algTime)