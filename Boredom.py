# choose an element ak from the array and you need to delete ak , ak - 1, ak + 1
# this will give us ak points
# find the max points one can score
from collections import Counter

n = int(input())
array = list(map(int, input().split()))

# Step 1: Count the occurrences of each number
cnt = [0] * (max(array) + 1) 
for num in array:
    cnt[num] += 1

dp = [0] * (len(cnt))  
dp[1] = cnt[1] 

if len(cnt) > 2:
    dp[2] = max(dp[1], cnt[2] * 2)  # f(2) = max(f(1), cnt[2] * 2)

for i in range(3, len(cnt)):
    dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i)

print(dp[-1])
