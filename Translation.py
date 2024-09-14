# we have a word and in another language it is translated as reverse of that
# we are given both check if the given translation is correct
word = input()
reversed_word = input()
reversed_word = reversed_word[ : : -1]

if word == reversed_word:
    print("YES")
else:
    print("NO")