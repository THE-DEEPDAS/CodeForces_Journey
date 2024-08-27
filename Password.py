# we need to find a substring t of a string s such that t is prefix + suffix + appears 
# somewhere in middle also in string s
# example fixprefixsuffix so fix is appearing at start + end + middle of string s
s = input()
n = len(s)
possible_answers = []

for i in range(n):  # prefix can't be empty string
    prefix = s[ : i]  
    suffix = s[-i : ]
    if prefix == suffix:
        if prefix in s[:]:  
            possible_answers.append(prefix)

if possible_answers:
    print(possible_answers[-1])
else:
    print("Just a legend")