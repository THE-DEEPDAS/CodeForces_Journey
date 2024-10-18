MOD = 10**9 + 7
t = int(input())

n_values = list(map(int, input().split()))
k_values = list(map(int, input().split()))

for i in range(t):
    k = k_values[i]
    
    # Efficiently compute 2^k % MOD
    result = pow(2, k, MOD)
    print(result)