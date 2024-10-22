# We need to find the center of a circle denoted by # and other elements are .
testcases = int(input())

for _ in range(testcases):
    rows, cols = list(map(int, input().split()))

    matrix = []
    for row in range(rows):
        col = list(input().strip())
        matrix.append(col)

    max_count_row, max_in_row = 0, 0
    start_row, end_row = -1, -1

    # Finding the row with the maximum count of '#' and their positions
    for r in range(rows):
        count = 0
        current_start, current_end = -1, -1

        for c in range(cols):
            if matrix[r][c] == '#':
                count += 1
                if current_start == -1:  
                    current_start = c
                current_end = c  
       
        if count > max_count_row:
            max_count_row = count
            max_in_row = r + 1  
            max_in_col = (current_start + current_end) // 2 + 1
            

    print(str(max_in_row) + " " + str(max_in_col))
