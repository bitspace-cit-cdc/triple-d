def divisorGame(n):
    return n % 2 == 0

n = int(input())
print("True" if divisorGame(n) else "False")