# This code is a translation from C++ to Python and uses standard input/output.
class FastIO:
    def __init__(self):
        import sys
        input = sys.stdin.read
        sys.stdin = open(0)  # Disable C I/O synchronization
        sys.stdout = open(1, 'w')  # Untie cin and cout for faster input/output

fast_io_setup = FastIO()  # This will be executed before main()

def main():
    n = int(input().strip())
    num = list(map(int, input().strip().split()))

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + num[i]

    sz = n * (n + 1) // 2
    sums = [0] * (sz + 1)
    idx = 1
    for l in range(n):
        for r in range(l, n):
            sums[idx] = sums[idx - 1] + (pre[r + 1] - pre[l])
            idx += 1

    q = int(input().strip())
    for _ in range(q):
        l, r = map(int, input().strip().split())
        print(sums[r] - sums[l - 1])

if __name__ == "__main__":
    main()