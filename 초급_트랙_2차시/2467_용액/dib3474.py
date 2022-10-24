import math
import sys
input = sys.stdin.readline

N = int(input())

L = list(map(int, input().split()))

L.sort(key=abs)

low = 2000000000

for i in range(N-1):
    gap = abs(L[i] + L[i+1])
    if low > gap:
        low = gap
        index = i
a = L[index]
b = L[index+1]
if a > b:
    a, b = b, a

print(a, b)
