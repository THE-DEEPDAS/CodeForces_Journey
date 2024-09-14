def calculate_value(character_list):
    total_value = 0
    for index in range(len(character_list)):
        if character_list[index] == '<':
            total_value += 10
        elif character_list[index] == 'v':
            total_value += 1
        elif character_list[index] == '0':
            total_value += 0
    return total_value

def main():
    test_cases = int(input())
    
    while test_cases > 0:
        input_string = input()
        
        temporary_list = []
        result_list = []
        for index in range(len(input_string)):
            if input_string[index] == ' ':
                result_list.append(temporary_list)
                temporary_list = []
            else:
                temporary_list.append(input_string[index])
        if temporary_list:  # to handle the last word
            result_list.append(temporary_list)

        calculated_values = []
        for index in range(len(result_list)):
            calculated_values.append(calculate_value(result_list[index]))

        multiplier = 1
        final_answer = 0
        number_of_values = len(calculated_values)
        for index in range(number_of_values - 1, -1, -1):
            final_answer += (calculated_values[index] * multiplier)
            multiplier *= 60
        
        print(final_answer)
        test_cases -= 1

if __name__ == "__main__":
    main()