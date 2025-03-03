def solve():
    s = input().strip()
    stack = []
    result = 0
    num = 0
    sign = 1
    openParentheses = 0
    lastWasOperator = True
    
    i = 0
    while i < len(s):
        ch = s[i]

        if ch == ' ':
            i += 1
            continue

        if ch.isdigit():
            num = num * 10 + int(ch)
            lastWasOperator = False
        elif ch == '+' or ch == '-':
            if lastWasOperator:
                print("invalid")
                return
            result += sign * num
            sign = 1 if ch == '+' else -1
            num = 0
            lastWasOperator = True
        elif ch == '(':
            if not lastWasOperator:
                print("invalid")
                return
            stack.append(result)
            stack.append(sign)
            result = 0
            sign = 1
            openParentheses += 1
            lastWasOperator = False
        elif ch == ')':
            if openParentheses == 0 or lastWasOperator:
                print("invalid")
                return
            result += sign * num
            sign = stack.pop()
            result *= sign
            result += stack.pop()
            num = 0
            openParentheses -= 1
            lastWasOperator = False
        else:
            print("invalid")
            return

        i += 1

    if openParentheses != 0 or lastWasOperator:
        print("invalid")
        return

    result += sign * num
    print(result)


t = int(input())
for _ in range(t):
	solve()