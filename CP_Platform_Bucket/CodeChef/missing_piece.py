# cook your dish here
letters = {'a': 2, 'b': 0, 'c': 1, 'd': 2, 'e': 3, 'f': 1, 'g': 2, 'h': 0,
            'i': 1, 'j': 10, 'k': 0, 'l': 1, 'm': 2, 'n': 0, 'o': 1,
            'p': 2, 'q': 3, 'r': 1, 's': 2, 't': 3, 'u': 4, 'v': 2,
            'w': 3, 'x': 1, 'y': 2, 'z': 0}
n = input()
if len(n) < 4:
    print("Enter the inputs within range! Length of string should be atleast 4.")
else:
    value = 0
    for letter in n:
        try:
            i = int(letter)
            value += 0
        except:
            if letter.isalpha():
                letter = letter.lower()
                value += letters[letter]
            else:
                value += 0
    print(value % 11)

# You can find the problem statement at https://www.codechef.com/problems/SRCOR2