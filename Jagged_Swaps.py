# in a permutation of n numbers select index from 2 to n - 1 such that
# ai -1 < ai and ai > ai + 1 , swap(ai , ai + 1)
# is it possible to sort the permutations
def can_sort_permutation(a):
    n = len(a)
    if a == sorted(a):
        return True
    
    for _ in range(n):
        sorted_flag = True
        for i in range(1, n - 1):
            if a[i - 1] < a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                sorted_flag = False
        
        # if we cannot find any peak to swap then break the loop
        if sorted_flag:
            break
    
    return a == sorted(a)

t = int(input())
results = []

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    if can_sort_permutation(a):
        results.append("YES")
    else:
        results.append("NO")

print("\n".join(results))