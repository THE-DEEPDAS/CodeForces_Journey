# An+1 = An + minDigit(An) * MaxDigit(An)
# here min and max digits are from the decimal representation of the number
# find Ak
def helper(A):
    min_digit = min(int(d) for d in str(A))
    max_digit = max(int(d) for d in str(A))
    return A + min_digit * max_digit

testcases = int(input())

for _ in range(testcases):
    A, k = input().split()
    k = int(k)
    A = int(A)
    
    for i in range(k - 1):
        min_digit = min(int(d) for d in str(A))
        if min_digit == 0:
            break
        A = helper(A)
    
    print(A)
