import sys

input = sys.stdin.readline

N = int(input())

L = []
for _ in range(N):
    L.append(int(input()))

L.sort(reverse=True)

result = []
for i in range(N):
    tmp = L[i]-i
    if tmp > 0:
        result.append(L[i]-i)

print(sum(result))
