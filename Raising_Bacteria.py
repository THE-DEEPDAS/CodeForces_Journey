# We are tasked with putting some bacteria in a box each day, and each night, the bacteria splits into 2 parts.
# We need to figure out how many bacteria should be put across days to see 'x' bacteria on a particular day.

def min_bacteria(x):
    # Initialize the lower bound to 1 (starting with one bacteria)
    lower_bound = 1

    # Continue doubling the lower bound until it exceeds or equals 'x'
    while lower_bound <= x:
        lower_bound *= 2

    # The minimum number of bacteria to put in the box to see exactly 'x' bacteria
    # is given by 1 + x - (lower_bound / 2)
    # lower_bound / 2 is the last value that was less than or equal to 'x'
    return 1 + x - (lower_bound // 2)

# Input
x = int(input())

# Output the result
print(min_bacteria(x))
