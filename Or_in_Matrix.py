# m rows and n columns in a matrix
# new matrix has elements which are OR of all elements in row i and column j
# we are given new matrix tell that can it be made and if yes then make it
# so we are applying reverse engineering that if an element in B is 0 means that row and column will not have 1
# so make all the elements in row i and column j of A to be 0
# when 1 will come it will be minimimised as 0's marking will be removed in one place
m, n = map(int, input().split())

# Read the matrix B
B = [list(map(int, input().split())) for _ in range(m)]

# Initialize matrix A with all elements as 1
A = [[1] * n for _ in range(m)]

# Determine which rows and columns should be zeroed in A
for i in range(m):
    for j in range(n):
        if B[i][j] == 0:
            for k in range(m):
                A[k][j] = 0
            for k in range(n):
                A[i][k] = 0

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