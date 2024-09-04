# choose an element ak from the array and you need to delete ak , ak - 1, ak + 1
# this will give us ak points
# find the max points one can score
from collections import Counter

n = int(input())
array = list(map(int, input().split()))

freq = Counter(array)
unique_numbers = sorted(freq.keys(), reverse=True)

points = 0

for num in unique_numbers:
    if freq[num] > 0 and (((num - 1) * freq[num - 1] <= num * freq[num]) and ((num + 1) * freq[num + 1] <= num * freq[num])):
        if((((num - 1) * freq[num - 1] + (num + 1) * freq[num + 1]) > num * freq[num])):
            points += (num - 1) * freq[num - 1] + (num + 1) * freq[num + 1]
        else:
            points += num * freq[num]
            del freq[num]
            if num - 1 in freq:
                del freq[num - 1]
            if num + 1 in freq:
                del freq[num + 1]

print(points)