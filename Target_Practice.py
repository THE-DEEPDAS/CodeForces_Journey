# we have grids with '.' and 'X' characters where 'X' represents hits of arrow
# we have point atructure that innermost = 5 and outermost = 1
# find the points he scored
testcases = int(input())

for _ in range(testcases):
    grid = []
    
    for _ in range(10):
        row = list(input().strip())
        grid.append(row)

    points = 0
    for i in range(10):
        for j in range(10):
            if grid[i][j] == 'X':
                # this is more optimal as it not requires if else statements
                # score = min(i+1, j+1, 10-i, 10-j)
                # points += score
                if i == 0 or i == 9 or j == 0 or j == 9:
                    points += 1
                elif i == 1 or i == 8 or j == 1 or j == 8:
                    points += 2
                elif i == 2 or i == 7 or j == 2 or j == 7:
                    points += 3
                elif i == 3 or i == 6 or j == 3 or j == 6:
                    points += 4
                else:
                    points += 5
    print(points)