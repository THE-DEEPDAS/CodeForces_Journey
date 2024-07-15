# draw on n by m table
#(r,c) -> cth cell on rth row
# The tail is at (1, 1),body extends to (1, m), goes down 2 rows to (3, m), goes left to (3, 1) and so on.

n = int(input()) # numberof rows
m = int(input()) # number of cells

for i in range(n):
    if i % 2 == 0:
        print('#' * m)
    elif (i + 1) % 4 == 0:
            if m == 1:
                print('#')
            else:
                print('#' + '.' * (m - 1))
    else:
        if m == 1:
            print('#')
        else:
            print('.' * (m - 1) + '#')