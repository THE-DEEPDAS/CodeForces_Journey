# We are tasked with putting some bacteria in a box each day, and each night, the bacteria splits into 2 parts.
# We need to figure out how many bacteria should be put across days to see 'x' bacteria on a particular day.

def min_bacteria(n):
    # Count the number of set bits (1s) in the binary representation of n
    return bin(n).count('1')

n = int(input())

# Output the result
print(min_bacteria(n))
