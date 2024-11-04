# just find the sum of digits in a number
testcases = int(input())

for _ in range(testcases):
    num = input()
    answer = 0
    for __ in num:
        answer += int(__)
    print(answer)