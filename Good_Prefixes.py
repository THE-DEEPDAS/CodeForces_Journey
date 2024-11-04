# an array is considered good if any element in the array can be represented as sum of elements
# so we need to find number of good prefixes in the given array
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    total_sum = 0  
    max_so_far = 0  
    ans = 0  

    for i in range(n):
        max_so_far = max(max_so_far, a[i]) 
        total_sum += a[i]  
        
        if total_sum == 2 * max_so_far:
            ans += 1

    print(ans)

