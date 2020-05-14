from fractions import Fraction
def badSort(arrayObj,start, end, alpha):
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

infile = open("data.txt")
outfile = open("bad.out","w")
array = []
a = input("Please enter a fraction between 1/2 and 1 for the value of alpha\n")
a = float(Fraction(a))
for line in infile:
    array.append([int(i) for i in line.split()])
for list in array:
    n = list.pop(0)
    badSort(list, 0, n, a)
    for number in list:
        outfile.write("%d " % number)
    outfile.write("\n")

infile.close()
outfile.close()