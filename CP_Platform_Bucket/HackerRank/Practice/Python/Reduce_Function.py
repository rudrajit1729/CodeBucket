"""

Submission link:

https://www.hackerrank.com/challenges/reduce-function/submissions/code/184105046

"""

from fractions import Fraction
from functools import reduce

def product(fracs):
    f = Fraction(reduce(lambda x, y: x * y, fracs))
    return f.numerator, f.denominator

if __name__ == '__main__':
    fracs = []
    for _ in range(int(input())):
        fracs.append(Fraction(*map(int, input().split())))
    result = product(fracs)
    print(*result)
