def solve():
    s = input().strip()
    stack = []
    ans = 0
    for i in range(len(s)):
        if s[i] in "({[":
            stack.append((s[i], i))
        else:
            if not stack:
                print(0)
                return
            top_char, top_index = stack[-1]
            if (
                (s[i] == ")" and top_char == "(")
                or (s[i] == "}" and top_char == "{")
                or (s[i] == "]" and top_char == "[")
            ):
                ans = max(ans, i - top_index + 1)
                stack.pop()
            else:
                print(0)
                return
    print(ans)


t = int(input())
for _ in range(t):
    solve()