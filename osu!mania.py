# we are given a string of n rows and 4 columns 
# we have to find the column number in which '#' appears
# start from the last row
testcases = int(input())

for _ in range(testcases):
    rows = int(input())
    ans = []
    for __ in range(rows):
        row = input()
        for i in range(3, -1, -1):
            if row[i] == '#':
                ans.append(i + 1)
    
    ans.reverse()  # reverse the order to get the correct column numbers
    print(*ans)