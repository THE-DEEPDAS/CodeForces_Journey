# We need to find the center of a circle denoted by # and other elements are .
testcases = int(input())

for _ in range(testcases):
    rows, cols = list(map(int, input().split()))

    matrix = []
    for row in range(rows):
        col = list(input().strip())
        matrix.append(col)

    max_count_row, max_in_row = 0, 0
    for r in range(rows):
        count = 0
        for c in range(cols):
            if matrix[r][c] == '#':
                count += 1
        if count > max_count_row:
            max_count_row = count
            max_in_row = r + 1  

    max_count_col, max_in_col = 0, 0  

    for c in range(cols):  
        count = 0
        for r in range(rows):  
            if matrix[r][c] == '#':
                count += 1
        
        if count > max_count_col:
            max_count_col = count
            max_in_col = c + 1  

    print(str(max_in_row) + " " + str(max_in_col))
