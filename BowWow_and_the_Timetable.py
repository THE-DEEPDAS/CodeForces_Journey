def binaryToDecimal(binary):
    decimal, i = 0, 0
    while binary != 0:
        dec = binary % 10
        decimal = decimal + dec * pow(2, i)
        binary = binary // 10
        i += 1
    return decimal

s = int(input())

decimal_rep = binaryToDecimal(s)

count = 0
power_of_4 = 1 

# kayo powers of 4 che je strictly less than decimal_representation che
while power_of_4 < decimal_rep:
    count += 1
    power_of_4 *= 4 

print(count)
