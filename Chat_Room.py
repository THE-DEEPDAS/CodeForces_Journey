s = input()
s.lower()

possible = []
needed = ['h' , 'e' , 'l' , 'o']
for _ in s:
    if _ in needed:
        possible.append(_)

word = "" 
for i in range(5): 
    word += possible[i]

if word == "hello":
    print("Yes")
else:
    print("No")