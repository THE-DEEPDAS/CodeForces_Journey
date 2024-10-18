# we have a binary string s
# add 1 to one ending and 0 to other end of the string
# we need to find the length of the shortest possible string we could have started with
def main():
    testcases = int(input())

    for testcase in range(testcases):
        n = int(input())
        s = input()

        removable = 0
        for i in range(n // 2):
            if (s[i] == '1' and s[n - i - 1] == '0') or (s[i] == '0' and s[n - i - 1] == '1'):
                removable += 2
            else:
                break

        print(n - removable)

if __name__ == "__main__":
    main()