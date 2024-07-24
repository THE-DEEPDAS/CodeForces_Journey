# m rows and n columns in a matrix
# new matrix has elements which are OR of all elements in row i and column j
# we are given new matrix tell that can it be made and if yes then make it
# Read dimensions
m, n = map(int, input().split())

# Read the matrix B
B = [list(map(int, input().split())) for _ in range(m)]

# Initialize matrix A with all elements as 0
A = [[0] * n for _ in range(m)]

# Set rows and columns in A based on B
for i in range(m):
    for j in range(n):
        if B[i][j] == 1:
            for k in range(n):  # Set row `i` to 1
                A[i][k] = 1
            for k in range(m):  # Set column `j` to 1
                A[k][j] = 1

# Compute the OR matrix from A
ored_matrix = [[0] * n for _ in range(m)]

for i in range(m):
    for j in range(n):
        ored_value = 0
        # OR operation over the entire row and column of A
        for k in range(n):
            ored_value |= A[i][k]
        for k in range(m):
            ored_value |= A[k][j]
        ored_matrix[i][j] = ored_value

# Compare ored_matrix with B
if ored_matrix == B:
    print("YES")
    for row in A:
        print(" ".join(map(str, row)))
else:
    print("NO")