# we have 2 dates DD.MM.YY when finals are going to happen
# and our birthday is BD.BM.BY
# can we rearrange our birthday so we are above 18 years of age
# years from 2001 to 2099 only
from datetime import datetime
from itertools import permutations

def is_leap_year(year):
    """Check if a year is a leap year."""
    return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)

def is_valid_date(day, month, year):
    """Check if the given day, month, and year form a valid date."""
    if month < 1 or month > 12:
        return False
    if day < 1:
        return False
    
    # Days in each month
    days_in_month = [31, 29 if is_leap_year(year) else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    return day <= days_in_month[month - 1]

def check_difference(d1, d2):
    """Check if the difference between two dates is at least 18 years."""
    if d1 > d2:
        d1, d2 = d2, d1
    year_diff = d2.year - d1.year
    if (d2.month, d2.day) < (d1.month, d1.day):
        year_diff -= 1
    return year_diff >= 18

def check_permutations(date1, date2):
    """Check all permutations of the birthday date against the finals date."""
    d1 = datetime.strptime(date1, "%d.%m.%y")
    
    day2, month2, year2 = date2.split('.')
    
    permuted_dates = set(permutations([day2, month2, year2]))
    
    for perm in permuted_dates:
        day, month, year = map(int, perm)
        if is_valid_date(day, month, year):
            d2 = datetime(year, month, day)
            if check_difference(d1, d2):
                return "YES"
    
    return "NO"

# Input dates
date1 = input("Enter the finals date (DD.MM.YY): ")
date2 = input("Enter your birthday (BD.BM.BY): ")

print(check_permutations(date1, date2))