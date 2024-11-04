str = input()

count1 = 0
count2 = 0
count3 = 0

for char in str:
    if char == '1':
        count1 += 1
    elif char == '2':
        count2 += 1
    elif char == '3':
        count3 += 1

answer = ""

if count1 > 0:
    for i in range(count1 - 1):
        answer += "1" + "+"
    if count2 != 0 or count3 != 0:
        answer += "1" + "+"
    else:
       answer += "1"

if count2 > 0:
    for i in range(count2 - 1):
        answer += "2" + "+"
    if count3 != 0:
        answer += "2" + "+"
    else:
        answer += "2"

if count3 > 0 :
    for i in range(count3-1):
        answer += "3" + "+"
    answer += "3"

print(answer)