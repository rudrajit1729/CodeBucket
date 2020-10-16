"""
Submission Link :-

https://www.hackerrank.com/challenges/validating-postalcode/submissions/code/175618195
"""

regex_integer_in_range = r"_________"	# Do not delete 'r'.
regex_alternating_repetitive_digit_pair = r"_________"	# Do not delete 'r'.

import re
s=input()
print (bool(re.match(r'^[1-9][\d]{5}$',s) and len(re.findall(r'(\d)(?=\d\1)',s))<2 ))
