def max_abs_diff(n, m):
    if n == 1:
        return 0
    elif n == 2:
        return m
    else:
        # Calculate maximum sum of absolute differences
        k = (n + 1) // 2  # Number of odd positions
        max_possible_value = m // k
        remainder = m % k
        
        # Maximum sum of differences
        if remainder == 0:
            return 2 * max_possible_value * (k - 1)
        else:
            return 2 * (max_possible_value * (k - 1) + remainder)
        
def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        results.append(max_abs_diff(n, m))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
