def myAtoi(s: str) -> int:
    i, n = 0, len(s)
    
    while i < n and s[i] == ' ':
        i += 1
    
    sign = 1
    if i < n and (s[i] == '+' or s[i] == '-'):
        sign = -1 if s[i] == '-' else 1
        i += 1
    
    if i < n and (s[i] == '0' and (i + 1 < n and s[i + 1] in 'xX')):
        i += 2
        hex_value = 0
        while i < n and s[i].lower() in '0123456789abcdef':
            hex_value = hex_value * 16 + int(s[i], 16)
            i += 1
        return sign * hex_value
    
    result = 0
    while i < n and s[i].isdigit():
        result = result * 10 + int(s[i])
        i += 1
    
    result *= sign
    
    INT_MIN, INT_MAX = -2**31, 2**31 - 1
    if result < INT_MIN:
        return INT_MIN
    if result > INT_MAX:
        return INT_MAX
    
    return result

s = input()
print(myAtoi(s))