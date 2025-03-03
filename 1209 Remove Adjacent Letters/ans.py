
def removeLetters(s: str, k: int, t: int) -> str:
    stack = []
    diffs = []
    prefix_diffs = [0]
    for c in s:
        if not stack:
            stack.append(c)
        else:
            diff = abs(ord(c) - ord(stack[-1]))
            stack.append(c)
            diffs.append(diff)
            prefix_diffs.append(prefix_diffs[-1] + diff)
        while len(stack) >= k:
            block_sum = prefix_diffs[len(diffs)] - prefix_diffs[len(diffs) - (k - 1)]
            if block_sum > t:
                for _ in range(k):
                    stack.pop()
                for _ in range(k - 1):
                    diffs.pop()
                    prefix_diffs.pop()
            else:
                break
    return "".join(stack)

s = input().strip()
k, t = map(int, input().split())
print(removeLetters(s, k, t))
