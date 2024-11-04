# we have a string of digits 0 to 9
# we have to put n - 2 additions or multiplications
# find the minimum number possible after doing such operations
testcases = int(input())

for _ in range(testcases):
    n = int(input())
    s = input()

    if n == 2:
        print(int(s))  # If there are only two digits, return the integer value directly
    else:
        # Initialize minimum values for the result of addition and multiplication
        min_add = float('inf')
        min_mult = float('inf')

        # Loop to consider each possible position for the two-digit number
        for i in range(1, n - 1):
            # Consider the two-digit number at position i
            two_digit = int(s[i:i+2])

            # Reset addition and multiplication starting from the first character as a single number
            add_result = int(s[0]) + two_digit
            mult_result = int(s[0]) * two_digit

            # Sum and multiply remaining digits individually
            for j in range(1, n):
                if j == i:  # Skip the two-digit number segment
                    continue
                add_result += int(s[j])
                mult_result *= int(s[j])

            # Track the minimum result for both addition and multiplication cases
            min_add = min(min_add, add_result)
            min_mult = min(min_mult, mult_result)

        # Output the minimum result from both addition and multiplication
        print(min(min_add, min_mult))
