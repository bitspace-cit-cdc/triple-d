def reverse_words(s):
    words = s.split()
    result = []

    for word in reversed(words):
        if len(word) % 2 != 0:
            result.append(word[::-1])
        else:
            result.append(word)

    return " ".join(result)

s = input().strip()
print(reverse_words(s))