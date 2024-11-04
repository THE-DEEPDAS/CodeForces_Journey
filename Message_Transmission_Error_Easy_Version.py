# 2 messages are merged if last of 1st message and start of 2nd message have some same chars
# we have the recieved message t , find if it is possibly merged and find original s
# print the message which could have caused the error
t = input()
t = list(t)
n = 0
for c in t:
    n += 1
start = n // 2 + 1
printed = False
while start < n:
    c = t[:start]
    d = t[n - start : ]

    if c == d:
        print("YES")
        ans = ""
        for i in c:
            ans += i
        print(ans)
        printed = True
        break
    start += 1
if not printed:
    print("NO")
