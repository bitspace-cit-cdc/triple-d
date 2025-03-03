
def remove_min(num: str, k: int) -> str:
    stack = []
    for c in num:
        while stack and k > 0 and stack[-1] > c:
            stack.pop()
            k -= 1
        stack.append(c)
    while k > 0 and stack:
        stack.pop()
        k -= 1
    res = "".join(stack).lstrip("0")
    return res if res != "" else "0"

def remove_max(num: str, k: int) -> str:
    stack = []
    for c in num:
        while stack and k > 0 and stack[-1] < c:
            stack.pop()
            k -= 1
        stack.append(c)
    while k > 0 and stack:
        stack.pop()
        k -= 1
    res = "".join(stack).lstrip("0")
    return res if res != "" else "0"

num = input().strip()
k = int(input())
min_num = remove_min(num, k)
max_num = remove_max(num, k)
result = abs(int(max_num) - int(min_num))
print(result)
