def solve_mode_sequence(n, arr):
    # Track frequency of each number
    freq = {}
    # Track frequency needed at each step
    step_freq = {}
    # Result array to be constructed
    result = [0] * n
    
    # Iterate through the input array
    for i in range(n):
        # Current number
        num = arr[i]
        
        # Update frequency tracking
        freq[num] = freq.get(num, 0) + 1
        
        # Find the mode (number with maximum frequency)
        mode = max(freq, key=freq.get)
        
        # Update step frequency needed
        step_freq[mode] = step_freq.get(mode, 0) + 1
        
        # Set the result at current position
        if freq[mode] == step_freq[mode]:
            # If current frequency matches step frequency, use mode
            result[i] = mode
        else:
            # Otherwise, use the first number that satisfies current frequency requirements
            for j in range(1, n+1):
                if freq.get(j, 0) >= step_freq.get(mode, 0):
                    result[i] = j
                    break
    
    return result

# Read number of test cases
t = int(input())

# Process each test case
for _ in range(t):
    # Read length of array
    n = int(input())
    
    # Read input array
    arr = list(map(int, input().split()))
    
    # Solve and print result
    result = solve_mode_sequence(n, arr)
    print(*result)