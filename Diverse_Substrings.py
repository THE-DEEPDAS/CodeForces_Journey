# diverse string means no letter appears n/2 times
# return any sub-string that is diverse
def find_diverse_substring(s, n):
    # Iterate over all possible starting indices of the substring
    for i in range(n):
        count = {}
        # Extend the substring from index i to j
        for j in range(i, n):
            char = s[j]
            count[char] = count.get(char, 0) + 1
            # Check if the substring is valid
            if max(count.values()) <= (j - i + 1) // 2:
                # Return the substring if it is diverse and has more than one character
                if j - i + 1 > 1:
                    return s[i:j+1]
    return "NO"

# Read input
n = int(input())
s = input()

# Compute and print the result
result = find_diverse_substring(s, n)
if result == "NO":
    print(result)
else:
    print("YES")
    print(result)