# swap the first digits of a and b string
testcases = int(input())

for _ in range(testcases):
    a, b = input().split()

    c = a[0] + b[1] + b[2]
    d = b[0] + a[1] + a[2]

    print(d + " " + c)