"""
Submission link:
https://www.hackerrank.com/challenges/the-minion-game/submissions/code/177677337
"""

def minion_game(string):
    s1=0
    s2=0
    vowels='AEIOU'
    for i in range(len(s)):
        if s[i] not in vowels:
            s1=s1+(len(s) -i)
        else:
            s2=s2+(len(s)-i)
    if s1>s2:
        print("Stuart",s1)
    elif s1<s2:
        print("Kevin",s2)
    else:
        print("Draw")
    
if __name__ == '__main__':
    s = input()
    minion_game(s)
 
