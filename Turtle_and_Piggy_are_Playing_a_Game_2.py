# in a game turtle always takes first turn and then on alternate turns
# we have n lengthed integer sequence, if current length = 1 then end the game
# on turtle's turn set ai to max(ai, ai+1) and remove ai+1
# on piggy's turn set ai to min(ai, ai+1) and remove ai+1
# find the value left at end
# so turtle wants to maximise the value of a1 and piggy wants to minimise the value of a1
# so we have to find how many turns each will get 
testcases = int(input())

for testcase in range(testcases):
    n = int(input())
    a = list(map(int, input().split()))

    if n % 2 != 0:
        turtle_turns = (n - 1) // 2
    else:
        turtle_turns = n // 2
    piggy_turns = n - turtle_turns - 1

    # now on each turtle's turn we remove min value from current array 
    # and on each piggy's turn we remove max value from current array
    a.sort()
    a = a[:n - piggy_turns]
    a = a[turtle_turns:] 

    print(a[0])