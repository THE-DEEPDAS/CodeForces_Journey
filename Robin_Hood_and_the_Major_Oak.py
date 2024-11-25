def count_odds_in_range(l, r):
    if l % 2 == 0:
        l += 1
    
    if r % 2 == 0:
        r -= 1
    # hello
    if l > r:
        return 0
    
    return (r - l) // 2 + 1

def solve():
    t = int(input())
    
    for _ in range(t):
        n, k = map(int, input().split())
        l = n - k + 1
        r = n
      
        odd_count = count_odds_in_range(l, r)
        if odd_count % 2 == 0:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    solve()
