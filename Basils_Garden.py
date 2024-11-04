# there are n flowers with ith one having the height hi
# we have to make all flowers height = 0
# in each second a wind blows and reduces height of hi by 1 is hi > hi + 1 or if i == n

testcases = int(input())

for _ in range(testcases):
    n = int(input())
    heights = list(map(int, input().split()))
    
    ans = heights[n - 1]
    for i in range (n - 2, -1, -1):
        ans = max(ans + 1, heights[i])
    
    print(ans)
    