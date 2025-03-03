def generate(numRows):
    result = []
    for row in range(numRows):
        current_row = [1] * (row + 1)
        for i in range(1, row):
            current_row[i] = result[row - 1][i - 1] + result[row - 1][i]
        result.append(current_row)

    flattened = [num for row in result for num in row]
    return flattened

numRows = int(input())

print(generate(numRows))