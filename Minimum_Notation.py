# We are given a string of digits. For each digit, we can increment it by 1 (up to 9).
# Our goal is to find the lexicographically smallest string possible.
# We process digits from 0 to 9, moving each occurrence to any index after incrementing.
# we need to delete the charachter for adding the min(num + 1, 9) to any position

testcases = int(input())
for _ in range(testcases):
    s = list(input().strip())  # Convert string to list of characters
    result = []  # To store the final result
    for num in s:
        num = int(num)
        mini = min(num + 1, 9)
        for i in s:
            if int(i) > mini:
                # i need to put the mini at the first position and shift all 1 back
                result.insert(0, mini)
                s.remove(i)
            else:
                result.append(i)
    print(result)

