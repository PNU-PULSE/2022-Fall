
import math
import sys
input = sys.stdin.readline

prime = [1]*100001

for i in range(2, math.ceil(math.sqrt(len(prime)))):
    if prime[i] == 1:
        j = 2
        while(j*i < 100000):
            prime[i*j] = 0
            j += 1

T = int(input())

for _ in range(T):
    case = []
    n = int(input())
    for i in range(2, math.ceil(n//2)+1):
        if prime[i] and prime[n-i]:
            case.append((n-2*i, i, n-i))
            
    print(f"{min(case)[1]} {min(case)[2]}")
