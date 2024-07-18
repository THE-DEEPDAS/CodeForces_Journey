# deletes all the vowels,
# inserts a character "." before each consonant,
# replaces all uppercase consonants with corresponding lowercase ones.

vowels = "AEIOUYaeiouy"
s = input()

answer = ""
for letter in s:
    if letter in vowels:
        continue
    answer += letter.lower()

dot = "."
real_answer = ""
for i in range(2 * len(answer)):
    if i % 2 == 0:
        real_answer += dot
    else:
        real_answer += answer[i // 2]

print(real_answer)
    
