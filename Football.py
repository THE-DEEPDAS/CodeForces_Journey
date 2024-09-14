# we have string of players of 2 teams
# 0 represents 1 team, 1 represents other team
# it is dangerous if 7 people of same team are standing togather
# find if the situation is dangerous
s = input()
s = list(s)

found = True

for i in range(len(s) - 6):
    if s[i] == '0':
        found = True
        n = 7
        while n > 0:
            if s[i] == '1':
                found = False
                break
            n -= 1
            i += 1
        if found:
            print('YES')
            exit()
    else:
        found = True
        n = 7
        while n > 0:
            if s[i] == '0':
                found = False
                break
            n -= 1
            i += 1
        if found:
            print('YES')
            exit()

print("NO")

    
        
