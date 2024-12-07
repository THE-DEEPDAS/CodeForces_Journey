def solve(n, m, k, s):
    # If we can strengthen a single spot or entire range is already strong
    if m == 1:
        return sum(1 for c in s if c == '0')
    
    # Track the last position we've strengthened
    last_strengthened = -k
    
    # Count of Timar uses
    timar_uses = 0
    
    # Scan through the string
    for i in range(n):
        # Check if current window of m spots is weak
        is_weak_window = all(s[max(0, min(n-1, j))] == '0' for j in range(i, i+m))
        
        # If weak window and we can apply Timar
        if is_weak_window and i >= last_strengthened + k:
            # Use Timar to strengthen the window
            timar_uses += 1
            last_strengthened = i + k - 1
    
    return timar_uses

# Read input and solve
testcases = int(input())
for _ in range(testcases):
    n, m, k = map(int, input().split())
    s = input()
    print(solve(n, m, k, s))