# make a pattern of 2*n + 1 lines
n = int(input())
n += 1 # done myself as 2n + 1 is what we need

for i in range(n):
    spaces = "  " * (n - i - 1)
    numbers = ""
    for j in range(i + 1):
        numbers += str(j) + " "
    end_nums = ""
    for j in range(i):
        end_nums += str(j) + " "
    end_nums = end_nums[::-1]
    # remove the leading space
    end_nums = end_nums[1:]
    ans = spaces + numbers + end_nums
    ans = ans.rstrip()  # remove the trailing space
    print (ans)

n -= 1 # as for lower we need n lines only
for i in range(n):
    spaces = "  " * (i + 1)
    numbers = ""
    for j in range(n - i):
        numbers += str(j) + " "
    end_nums = ""
    for j in range(n - i - 1):
        end_nums += str(j) + " "
    end_nums = end_nums[::-1]
    end_nums = end_nums[1:]
    ans = spaces + numbers + end_nums
    ans = ans.rstrip()
    print (ans)
