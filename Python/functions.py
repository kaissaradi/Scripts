def firstFit(capacity, items):  #function takes the capacity of each bin and a list of items
  bins = [0]    #create a list of bins, first bin has a current weight of zero
  while len(items) > 0:   #pop first item from list
    firstItem = items.pop()
    for eachBin in bins:  #check each bin in list, if current weight is less than capcacity, add the item and break the loop
      if eachBin <= capacity:
        eachBin += firstItem
        break
      else: #if the item cannot be added to any current bins, create a new bin and add the item
        bins.append(firstItem)

#merge sort functions to sort items list from increasing to decreasing
def mergeSortdec(array):
  if len(items) ==1:
    return items
  else:
    left = items[0...len(items)/2]
    right = items[len(items)/2 +1...len(item)]
    mergeSortdec(left)
    mergeSortdec(right)
    merge(left, right)

def merge(leftSide, rightSide):
  merged = []
  while leftSide and rightSide != empty:
    if leftSide[0] > rightSide[0]:
      merged.append(leftSide[0])
      leftSide.pop()
    else:
      merged.append(rightSide[0])
      rightSide.pop()
  return merged

def firstFitDec(capacity, items):
  #first fit decreasing simply requires we first sort our list of items
  mergeSortdec(items)
  firstFit(capacity, items)




def bestFit(capacity, items):
  bins = [0]  #create a list of bins, first one with weight zero
  minBin = [0,capacity] #a list describing the index and space remaining of the best bin that and item can fit in
  while len(items) > 0:
    currentItem =items.pop()
    itemFits = False
    for i in range(len(bins):
      itemFits = False
      if currentItem + bin[i] <= capacity:    #pop each item off the list and if it can fit in a bin, calculate the space remaining after adding it
        itemFits = True
        spaceRem = capacity - (currentItem + bin[i])
        if spaceRem < minBin[2]:    #if the space remaining in the bin is less than current best bin, update the best bin to add to
          minBin[0] = i
          minBin[1] = spaceRem
    if itemFits == False:   #if the item does not fit in any current bins, add it to a new bin
      bins.append(currentItem)
    else:   #otherwise add the current item to the bin at the index of the best bin.
      bins[minBin[0]] += currentItem

