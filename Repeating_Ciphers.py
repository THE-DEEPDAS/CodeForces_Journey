n = int(input())
s = input()

answer = ""
skip = 1
for i in range(0, n * (n + 1) // 2, skip):
    # Ensure that the index is within the bounds of the string
    if i < len(s):
        answer += s[i]
    skip += 1
print(answer)