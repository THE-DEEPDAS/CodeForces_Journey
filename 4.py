import math

def max_coins(n):
    # Handle base case where no transformation is possible
    if n <= 3:
        return 1
    # O(1) formula to calculate the maximum coins
    return 2 ** (math.floor(math.log(n, 4)) + 1)
