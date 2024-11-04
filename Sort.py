# we need to find the minimum number of swaps to make a part of string sorted

testcases = int(input())

for _ in range(testcases):
    n , q = map(int,input().split())
    a = input()
    b = input()

    for __ in range(q):
        l , r = map(int,input().split())
        swaps = 0
        part1 = a[l - 1 : r - 1]
        part2 = b[l - 1 : r - 1]
        sorted_part = sorted(part1)
        index = 0

        for i in range(l - 1,len(sorted_part), 1):
            if part1[i] != sorted_part[index]:
                swaps += 1

        index = 0
        for i in range(l - 1,len(sorted_part), 1):
            if part2[i] != sorted_part[index]:
                swaps += 1
                
        print(swaps // 2)