s=raw_input("\nEnter string")
def palin(s):
    if s==s[::-1]:
        print("\nPalindrome")
    else:
        print("Not palindrome")
palin(s)
