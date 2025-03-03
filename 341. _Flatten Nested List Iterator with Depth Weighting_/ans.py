def parse(s, pos):
    pos[0] += 1
    v = []
    while s[pos[0]] != ']':
        if s[pos[0]] == ',':
            pos[0] += 1
        elif s[pos[0]] == '-' or s[pos[0]].isdigit():
            sign = -1 if s[pos[0]] == '-' else 1
            if s[pos[0]] == '-':
                pos[0] += 1
            num = 0
            while pos[0] < len(s) and s[pos[0]].isdigit():
                num = num * 10 + int(s[pos[0]])
                pos[0] += 1
            v.append(sign * num)
        elif s[pos[0]] == '[':
            v.append(parse(s, pos))
    pos[0] += 1
    return v

def calculate_sum(v, d):
    s = 0
    for e in v:
        if isinstance(e, int):
            s += e * d
        else:
            s += calculate_sum(e, d + 1)
    return s


s = input().replace(" ", "")
pos = [0]
nested_list = parse(s, pos)
print(calculate_sum(nested_list, 1))