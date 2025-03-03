def titleToNumber(columnTitle):
    result = 0
    for char in columnTitle:
        result = result * 26 + ord(char) - ord('A') + 1
    return result

columnTitle = input()

print(titleToNumber(columnTitle))