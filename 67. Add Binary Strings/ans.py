def remove_leading_zeros(s):
    return s.lstrip('0') or '0'

def subtract_binary(a, b):
    if len(a) < len(b) or (len(a) == len(b) and a < b):
        a, b = b, a
    result = []
    carry = 0
    i, j = len(a) - 1, len(b) - 1
    while i >= 0:
        bitA = int(a[i])
        bitB = int(b[j]) if j >= 0 else 0
        diff = bitA - bitB - carry
        if diff < 0:
            diff += 2
            carry = 1
        else:
            carry = 0
        result.append(str(diff))
        i -= 1
        j -= 1
    return remove_leading_zeros(''.join(reversed(result)))

a = input().strip()
b = input().strip()
print(subtract_binary(a, b))