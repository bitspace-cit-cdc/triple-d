def decodeString(s: str) -> str:
    stack = []
    result = ""
    temp, temp1, temp2 = "", "", ""
    depth = 0
    
    for char in s:
        if char == '[':
            depth += 1
        if char == ']':
            depth -= 1
        
        if depth == 0 and char != ']' and char != '[' and not char.isdigit():
            result += char
        elif char == ']':
            while stack and stack[-1] != '[':
                temp += stack.pop()
            stack.pop()
            while stack and stack[-1].isdigit():
                temp1 += stack.pop()
            num = int(temp1[::-1]) if temp1 else 0
            temp2 = temp[::-1] * num
            if depth:
                for t in temp2:
                    stack.append(t)
            else:
                result += temp2
            temp, temp1, temp2 = "", "", ""
        else:
            stack.append(char)
    
    return result

s = input().strip()
print(decodeString(s))