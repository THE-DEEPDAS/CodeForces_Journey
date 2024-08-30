s = input().strip()
n = len(s)
printed = False

for length in range(n - 1, 0, -1):
    prefix = s[:length]
    suffix = s[-length:]

if prefix == suffix:
        if prefix in s[1:-1]:
            print(prefix)
            printed = True

if not printed: 
     print("Just a legend")