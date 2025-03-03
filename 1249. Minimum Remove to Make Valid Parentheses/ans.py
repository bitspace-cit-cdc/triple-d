def minRemoveToMakeValid(s):
    stack = []
    to_remove = set()
    matching = {')': '(', '}': '{', ']': '['}

    for i, char in enumerate(s):
        if char in matching.values():
            stack.append((char, i))
        elif char in matching.keys():
            if stack and stack[-1][0] == matching[char]:
                stack.pop()
            else:
                to_remove.add(i)

    for _, idx in stack:
        to_remove.add(idx)

    result = []
    for i, char in enumerate(s):
        if i not in to_remove:
            result.append(char)

    return ''.join(result)

s = input()
print(minRemoveToMakeValid(s))