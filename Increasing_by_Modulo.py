# we have n integer array whose numbers are in range 0 to m - 1 
# now we select an integer k and also array portion a1 to ak and replace each element with (element + 1) % m
# find min number of operations to make array non-decreasing

n, m = map(int, input().split())
nums = list(map(int, input().split()))

left, right = 0, m

while left < right:
    mid = left + (right - left) // 2
    flag = True
    
    # temporary list to hold the adjusted array
    test = nums[:]
    
    # adjust first element based on mid value
    if nums[0] + mid >= m:
        test[0] = 0  # wrap around using modulo
    else:
        test[0] = nums[0]
    
    # traverse the array to apply operations and check if it can be non-decreasing
    for i in range(1, n):
        if nums[i] < test[i - 1]:
            if nums[i] + mid < test[i - 1]:
                flag = False
                break
            else:
                test[i] = test[i - 1]
        else:
            if nums[i] + mid >= m and (nums[i] + mid) % m >= test[i - 1]:
                test[i] = test[i - 1]
            else:
                test[i] = nums[i]
    
    if flag:
        right = mid
    else:
        left = mid + 1

print(left)
