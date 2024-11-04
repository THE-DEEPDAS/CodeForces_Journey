t = int(input())

for _ in range(t):
    n = int(input())
    
    i = 0
    while(n >= (2 ** i)):
        i += 1
    
    print(( 2 ** i) - 1)