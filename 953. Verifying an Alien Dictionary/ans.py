def check(dic, words):
    ans = []
    for order in dic:
        orders = {}
        for j, char in enumerate(order):
            orders[char] = chr(j + ord('a'))

        word = []
        w1 = []

        for w in words:
            transformed = ''.join(orders[char] for char in w)
            word.append(transformed)
            w1.append(transformed)

        ans.append(sorted(w1) == word)

    return ans


if __name__ == "__main__":
    n, m = map(int, input().split())
    words = [input().strip() for _ in range(n)]
    dic = [input().strip() for _ in range(n)]
    
    ans = check(dic, words)
    print(" ".join(map(str, map(int, ans))))