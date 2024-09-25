import sys
import random

# Function to process the game and answer the queries
def solve():
    # Read the number of test cases
    t = int(sys.stdin.readline().strip())
    
    for _ in range(t):
        # Read n (number of targets) and q (number of queries)
        n, q = map(int, sys.stdin.readline().strip().split())
        
        # Read the array of scores for the targets
        a = list(map(int, sys.stdin.readline().strip().split()))
        
        # Generate unique random hashes for the target scores
        hash_map = {score: random.randint(1, 10**9) for score in set(a)}
        
        # Create a prefix XOR array
        prefix_xor = [0] * (n + 1)
        
        # Compute the prefix XOR array
        for i in range(1, n + 1):
            prefix_xor[i] = prefix_xor[i - 1] ^ hash_map[a[i - 1]]
        
        # Process each query
        for _ in range(q):
            l, r = map(int, sys.stdin.readline().strip().split())
            
            # Calculate the XOR for the range [l, r]
            range_xor = prefix_xor[r] ^ prefix_xor[l - 1]
            
            # Determine if Sheriff cannot lose and print the result immediately
            if range_xor == 0:
                sys.stdout.write("YES\n")
            else:
                sys.stdout.write("NO\n")
            
            # Ensure immediate output by flushing
            sys.stdout.flush()

if __name__ == "__main__":
    solve()
