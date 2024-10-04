# We have a matrix a of (n * m) elements
# We have to make a matrix b of the same order but a[i][j] != b[i][j]
testcases = int(input())

for _ in range(testcases):
    n, m = map(int, input().split())  # Read dimensions of the matrix
    
    a = []  # Input matrix a
    for i in range(n):
        row = list(map(int, input().split()))  
        a.append(row)

    if n == m == 1:
        print(-1)  # Impossible to create a different matrix with 1 element
        continue

    # Create matrix b as a shifted version of matrix a
    b = []
    for i in range(n):
        row_b = [0] * m  
        for j in range(m):  
            row_b[(j + 1) % m] = a[i][j]  # Right shift using modulo operator
        b.append(row_b)

    # Swap adjacent rows (row i with row i+1)
    for i in range(0, n - 1, 2):
        b[i], b[i + 1] = b[i + 1], b[i]

    # Print the matrix b
    for row in b:
        print(*row)  # Print row elements separated by spaces
