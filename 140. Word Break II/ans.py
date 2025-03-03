from functools import cache

def wordBreak(s, wordDict, scores):
    if not wordDict:
        return []

    wordToScore = {word: score for word, score in zip(wordDict, scores)}

    @cache
    def dfs(index):
        if index == len(s):
            return 0, [""]
        
        maxScore = float('-inf')
        bestSentences = []

        for word in wordDict:
            if s[index:index + len(word)] == word:
                remainingScore, sentences = dfs(index + len(word))
                totalScore = remainingScore + wordToScore[word]

                if totalScore > maxScore:
                    maxScore = totalScore
                    bestSentences = [sentence if sentence else word for sentence in sentences]
                elif totalScore == maxScore:
                    bestSentences.extend([sentence if sentence else word for sentence in sentences])
        
        return maxScore, bestSentences

    maxScore, sentences = dfs(0)
    return sentences if sentences else ["No Result"]

def solve():
    s = input().strip()
    n = int(input())
    wordDict = [input().strip() for _ in range(n)]
    scores = [int(input().strip()) for _ in range(n)]
    
    result = wordBreak(s, wordDict, scores)
    for sentence in result:
        print(sentence)


t = int(input())
for _ in range(t):
	solve()