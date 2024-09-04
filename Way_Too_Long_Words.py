# if a word is > 10 chars then it is encoded as <first char><chars in between><last char>
testcases = int(input())

for _ in range(testcases):
    word = input()
    if len(word) > 10:
        print(word[0] + str(len(word) - 2) + word[-1])
    else:
        print(word)