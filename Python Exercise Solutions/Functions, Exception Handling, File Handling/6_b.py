def checkPalindrome(str):
  reversedStr = str[::-1]
  return reversedStr == str

if __name__ == "__main__":
  str = input("Enter a word: ")
  if checkPalindrome(str):
    print(f"{str} is a palindrome string")
  else:
    print(f"{str} is not a palindrome string")
