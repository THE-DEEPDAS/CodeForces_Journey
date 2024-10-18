def longest_common_start(str1, str2):
    idx, ans = 0, 0
    for c in str1:
        # Check if idx is out of bounds for str2
        if idx >= len(str2) or str2[idx] != c:
            return ans
        ans += 1
        idx += 1
    return ans
 
testcases = int(input())
 
for _ in range(testcases):
    str1 = input()
    str2 = input()
 
    lcs = longest_common_start(str1, str2)
    if lcs:
        # Formula: 1 + len(str1) + len(str2) - lcs
        print(1 + len(str1) + len(str2) - lcs)
    else:
        # No common start, just return the combined lengths
        print(len(str1) + len(str2))
