# how many indices of a 10 digit string differs from 'codeforces'
# we can't reorder
# codeforces = {'c' : 2, 'o' : 2, 'd' : 1, 'e' : 2, 'f' : 1, 'r' : 1, 's' : 1}
testcases = int(input())

for _ in range(testcases):
    s = input()
    ans = 0

    if s[0] != 'c': ans += 1
    if s[1] != 'o': ans += 1
    if s[2] != 'd': ans += 1
    if s[3] != 'e': ans += 1
    if s[4] != 'f': ans += 1
    if s[5] != 'o': ans += 1
    if s[6] != 'r': ans += 1
    if s[7] != 'c': ans += 1
    if s[8] != 'e': ans += 1
    if s[9] != 's': ans += 1
    
    print(ans)