# we are given n integer number and we need to print 2n * 2n matrix with alternating sequence of 2 * 2 matrices
# which consits of # or . and start with 2 * 2 of #
testcases = int(input())

for _ in range(testcases):
    n = int(input())
    
    for i in range(2 * n):
        row = []
        for j in range(2 * n):
            if ((i // 2) % 2 == (j // 2) % 2):
                row.append('#')
            else:
                row.append('.')
        print("".join(row))
