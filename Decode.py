MOD = 10**9 + 7

# Number of test cases
testcases = int(input())

for _ in range(testcases):
    s = input().strip()  # Read the binary string
    n = len(s)
    count = 0

    # Iterate over all possible (l, r) pairs
    for l in range(n):
        for r in range(l, n):
            # Count '0's and '1's in the substring s[l:r+1]
            c0 = 0
            c1 = 0
            for k in range(l, r + 1):
                if s[k] == '0':
                    c0 += 1
                else:
                    c1 += 1
            if c0 == c1:
                count += 1

    print(count % MOD)
