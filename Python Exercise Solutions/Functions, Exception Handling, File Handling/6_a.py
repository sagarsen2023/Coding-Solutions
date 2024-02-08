def calculateSquare(val):
  return pow(val, 2)

if __name__ == "__main__":
  num = int(input("Enter any value: "))
  print(f"The square of {num} = {calculateSquare(num)}")
