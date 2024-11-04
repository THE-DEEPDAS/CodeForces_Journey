from sortedcontainers import SortedList

t = int(input().strip())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    sorted_a = SortedList(a)
    results = []

    for __ in range(m):
        op = input().split()
        sign, l, r = op[0], int(op[1]), int(op[2])

        if sign == '+':
            for i in range(n):
                if l <= a[i] <= r:
                    sorted_a.remove(a[i])
                    a[i] += 1
                    sorted_a.add(a[i])
        elif sign == '-':
            for i in range(n):
                if l <= a[i] <= r:
                    sorted_a.remove(a[i])
                    a[i] -= 1
                    sorted_a.add(a[i])

        results.append(sorted_a[-1])

    print(" ".join(map(str, results)))