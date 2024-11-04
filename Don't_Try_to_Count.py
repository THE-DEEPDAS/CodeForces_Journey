# we hvae a string x and we can perform operations which append x behind x 
# find min number of operations so that the string s will become substring of x
testcases = int(input())

for _ in range(testcases):
    count = 0
    n, m = map(int, input().split())
    x = input()
    s = input()
    
    current_x = x
    
    while len(current_x) < m:
        current_x += current_x
        count += 1

    # Check if `s` is a substring of the current `x`
    if s in current_x:
        print(count)
    else:
        # Extend `x` one more time and check again
        # for testcase where pattern not starts from 1st digit like bk and kbkbkbkb
        current_x += x
        count += 1
        if s in current_x:
            print(count)
        else:
            print(-1)