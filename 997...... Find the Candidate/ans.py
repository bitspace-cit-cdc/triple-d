def findJudges(n, trust):
    inDegree = [0] * (n + 1)
    outDegree = [0] * (n + 1)

    for t in trust:
        a, b = t
        outDegree[a] += 1
        inDegree[b] += 1

    judges = []
    for i in range(1, n + 1):
        if inDegree[i] >= n // 2 and outDegree[i] == 0:
            judges.append(i)
    
    return judges if judges else [-1]


if __name__ == "__main__":
    n = int(input())
    trust = [[1, 3], [2, 3], [4, 3]]
    result = findJudges(n, trust)
    print(*result)