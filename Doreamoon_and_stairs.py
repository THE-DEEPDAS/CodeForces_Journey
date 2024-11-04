# there are n stairs, he can climb 1 or 2 steps at a time
# find miinimum number of integer steps which is a multiple of m

n, m = map(int, input().split())

# if n is less than m
if n < m:
    print(-1)
else:
    # real logic
    multiples = float(float(n) / 2)
    if multiples == int(multiples):
        #completely divisible by 2
        multiples = int(multiples)
        if(multiples // m == float(multiples / m)):
            print(multiples)
            exit()
    else:
        # not completely divisible by 2
        multiples = n // 2 + 1
    # find the multiple of m just greater than multiples
        if(multiples // m == float(multiples / m)):
            print(multiples)
            exit()
    finder = multiples // m
    print(int((finder + 1)* m))
