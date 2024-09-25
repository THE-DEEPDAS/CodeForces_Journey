# we have 2 dates DD.MM.YY when finals are going to happen
# and our birthday is BD.BM.BY
# can we rearrange our birthday so we are above 18 years of age
# years from 2001 to 2099 only
from datetime import datetime
from itertools import permutations

# Function to check if the difference between two dates is more than 18 years
def check_difference(d1, d2):
    if d1 > d2:
        d1, d2 = d2, d1
    year_diff = d2.year - d1.year
    if (d2.month, d2.day) < (d1.month, d1.day):
        year_diff -= 1
    return year_diff >= 18

# Function to generate all permutations of the second date string
def check_permutations(date1, date2):
    # Parse the first date
    d1 = datetime.strptime(date1, "%d.%m.%y")
    
    # Extract components of the second date
    day2, month2, year2 = date2.split('.')
    
    # Generate all permutations of the day, month, and year for the second date
    permuted_dates = set(permutations([day2, month2, year2]))

    # Check each permutation
    for perm in permuted_dates:
        permuted_date_str = f"{perm[0]}.{perm[1]}.{perm[2]}"
        try:
            d2 = datetime.strptime(permuted_date_str, "%d.%m.%y")
            if check_difference(d1, d2):
                return "YES"  # Return "yes" if any permutation is more than 18 years
        except ValueError:
            # Skip invalid date permutations (e.g., 30.02.20)
            continue
    
    return "NO"  # Return "no" if none of the permutations work

# Example usage with inputs
date1 = input("")
date2 = input("")

# Output result
print(check_permutations(date1, date2))
