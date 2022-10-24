import sys

input = sys.stdin.readline

N = int(input())

cnt = 0
for _ in range(N):
    stack = []
    tmp = []
    L = list(input().rstrip())
    for x in L:
        if len(stack) > 0:
            if x == stack[-1]:   stack.pop()
            else:
                stack.append(x)
        else:
            stack.append(x)

    if len(stack) == 0:
        cnt += 1

print(cnt)
