# we have to insert a letter anywhere
# time for 1st char = 2s and for others if it is same as previous then 1s else 2s
# we need to make maximum time possible

def insert_character(input_string):
    if len(input_string) < 2:
        # Special case for single character input
        first_char = input_string[0]
        # Find the next character that is different from the first_char
        next_char = 'a'
        while next_char == first_char:
            next_char = chr(ord(next_char) + 1)
        return first_char + next_char
    
    first_char = input_string[0]
    second_char = input_string[1]

    # Calculate the previous character in the alphabet
    if first_char == 'a':
        prev_char = 'z'
    else:
        prev_char = chr(ord(first_char) - 1)
    
    # If the previous character is the same as the second character, adjust it
    if prev_char == second_char:
        if first_char == 'a':
            next_char = 'b'
        else:
            next_char = chr(ord(first_char) + 1)
    else:
        next_char = prev_char
    
    # Construct the new string
    result = first_char + next_char + input_string[1:]
    
    return result

def maximize_time(input_string):
    string_length = len(input_string)
    position = -1
    characters = set()  # Use a set to hold characters for faster lookup

    # Special case for single character string
    if string_length == 1:
        return insert_character(input_string)
    
    # Find position and record characters
    for index in range(string_length - 1):
        if input_string[index] == input_string[index + 1]:
            position = index + 1
            characters.add(input_string[index])
            characters.add(input_string[index + 1])
            break

    was_inserted = False
    # Try to insert a new character
    for character in range(ord('a'), ord('z') + 1):
        ch = chr(character)
        if ch not in characters:
            if position == -1 or position >= string_length:
                # Insert at index 1 if no valid position found
                insert_char = 'a' if string_length == 0 else ('a' if input_string[0] == 'z' else chr(ord(input_string[0]) - 1))
                input_string = input_string[:1] + insert_char + input_string[1:]
            else:
                input_string = input_string[:position] + ch + input_string[position:]
            was_inserted = True
            break
    
    if not was_inserted:
        input_string = insert_character(input_string)
    
    return input_string

# Example usage
test_cases_count = int(input())

for _ in range(test_cases_count):
    input_string = input()
    print(maximize_time(input_string))
