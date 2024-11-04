# 2 messages are merged if last of 1st message and start of 2nd message have some same chars
# we have the recieved message t , find if it is possibly merged and find original s
# print the message which could have caused the error
def build_failure_function(s):
    n = len(s)
    f = [0] * n
    j = 0  # length of the previous longest prefix suffix

    # build the failure function array
    for i in range(1, n):
        while (j > 0 and s[i] != s[j]):
            j = f[j - 1]  # fall back in the pattern

        if s[i] == s[j]:
            j += 1
            f[i] = j
        else:
            f[i] = 0  # no proper prefix which is also a suffix

    return f

t = input().strip()
f = build_failure_function(t)

if f[-1] * 2 > len(t):
    print("YES")
    print(t[:f[-1]])
else:
    print("NO")