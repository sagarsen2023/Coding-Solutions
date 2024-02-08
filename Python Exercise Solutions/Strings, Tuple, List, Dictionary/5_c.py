n = int(input("Enter the size of the list: "))
arr = []
for i in range(n):
  arr.append(int(input(f"Enter the value at {i} position: ")))

print(f"Original array: {arr}")

updatedElements = set(arr)
arr = list(updatedElements)

print("Updated array: ", arr)
