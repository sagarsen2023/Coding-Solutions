dataDict = {}

n = int(input("Enter the size of the dictionary: "))

for i in range(n):
  dataDict[i] = int(input(f"Enter the value at key {i+1}: "))

if len(dataDict) == 0:
  print("The dictionary is empty.")
else:
  maximumValue = 0
  for _, value in dataDict.items():
    if maximumValue < value:
      maximumValue = value
  print("The maximum value is: ", maximumValue)
