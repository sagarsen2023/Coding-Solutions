def getCommonNumbers(arr1, arr2):
  commonElements = []
  for element in arr1:
    if element in arr2:
      commonElements.append(element)

  return commonElements

n1 = int(input("Enter the size of the first list: "))
n2= int(input("Enter the size of the first list: "))

arr1 = []
arr2 = []

print("Enter the elements for the first List: ")
for i in range(n1):
  arr1.append(int(input(f"Enter the value at {i} position: ")))

print("Enter the elements for the second List: ")
for i in range(n2):
  arr2.append(int(input(f"Enter the value at {i} position: ")))


if (n1 > n2):
  print(f"Common Elements: {getCommonNumbers(arr1, arr2)}")
else:
  print(f"Common Elements: {getCommonNumbers(arr2, arr1)}")
    
