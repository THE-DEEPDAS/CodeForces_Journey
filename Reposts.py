#the initial post is only with polycarp
# when person 1 posts person 2 , if person 2 has post then person 1 also gets it
# find the max consecutive length of posts
n = int(input())
reposts = [input().split() for _ in range(n)]

post_length = {'polycarp': 1} 
max_length = 1 

for name1, _, name2 in reposts:
    name1 = name1.lower()
    name2 = name2.lower()

    post_length[name1] = post_length[name2] + 1 # update the length for name1's chain
    max_length = max(max_length, post_length[name1])

print(max_length)