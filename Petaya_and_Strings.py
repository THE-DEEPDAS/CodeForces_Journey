# we have 2 strings s1 and s2
# find if string 1 is greater than string 2 , equal to string 2 or lesser than string 2
s1 = input()

s2 = input()

if s1.lower() == s2.lower():
    print(0)
elif s1.lower() < s2.lower():
    print(-1)
else:
    print(1)