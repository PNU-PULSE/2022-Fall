import sys
import heapq

N = int(sys.stdin.readline())

L = []

for _ in range(N):
    heapq.heappush(L, int(sys.stdin.readline()))

result = 0
while(True):
    if len(L) < 2:
        print(result)
        break
    cnt = heapq.heappop(L) + heapq.heappop(L)
    result += cnt
    if len(L) == 0:
        print(result)
        break
    heapq.heappush(L, cnt)
