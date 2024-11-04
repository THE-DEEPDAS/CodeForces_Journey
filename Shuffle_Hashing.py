# we need to understand hash of the password that will be stored
# take a password p and shuffle it randomly to obtain p'
# generate 2 random strings
# hash h = s1 + p' + s2
# check if the given hash can be the hash of the password p
# testcases , then p then h are given for each testcase.

testcases = int(input())

for testcase in range(testcases):
    # Taking inputs
    p = input()
    h = input()

    # Initialize hashmap to count characters in p
    hashmap = {}
    for c in p:
        if c in hashmap:
            hashmap[c] += 1
        else:
            hashmap[c] = 1

    # Length of the password and hash
    len_p = len(p)
    len_h = len(h)

    found = False

    # Check each substring of length len_p in h
    for i in range(len_h - len_p + 1):
        # Copy hashmap to keep track of characters in the current window
        copy_hashmap = hashmap.copy()
        valid = True

        for j in range(i, i + len_p):
            if h[j] in copy_hashmap:
                copy_hashmap[h[j]] -= 1
                if copy_hashmap[h[j]] == 0:
                    del copy_hashmap[h[j]]
            else:
                valid = False
                break

        # Check if all counts are zero
        if valid and not copy_hashmap:
            print("YES")
            found = True
            break

    if not found:
        print("NO")