# we have a string which represents a square matrix
# a matrix is beautiful if its corners have 1 , else all in middle = 0
# check if s can be squared
import math

def is_beautiful_binary_matrix(n, s):
    # check if n is a perfect square
    side_length = int(math.isqrt(n))
    if side_length * side_length != n:
        return "No"
    
    # convert the string to matrix
    for i in range(side_length):
        # 1st , last row
        if i == 0 or i == side_length - 1:
            if s[i * side_length:(i + 1) * side_length] != '1' * side_length:
                return "No"
        else:
            # middle rows
            if s[i * side_length] != '1' or s[(i + 1) * side_length - 1] != '1':
                return "No"
            if s[i * side_length + 1:(i + 1) * side_length - 1] != '0' * (side_length - 2):
                return "No"
    
    return "Yes"

t = int(input())
results = []
for _ in range(t):
    n = int(input())
    s = input().strip()
    results.append(is_beautiful_binary_matrix(n, s))

print("\n".join(results))
