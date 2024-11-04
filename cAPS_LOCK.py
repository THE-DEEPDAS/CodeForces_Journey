string = input()

check = True

for i in range(1,len(string)):
    if string[i].isupper():
        continue
    else:
        check = False
        break

if check:
    for i in range(len(string)):
        if string[i].isupper():
            print(string[i].lower(), end='')
        else:
            print(string[i].upper(), end='')

else:
    print(string)