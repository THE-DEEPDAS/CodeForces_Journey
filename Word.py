word = input()

lower = 0
upper = 0
for ch in word:
    if ch >= 'A' and ch <= 'Z':
        upper += 1
    else:
        lower += 1

if(upper > lower):
    print(word.upper())
else:
    print(word.lower())