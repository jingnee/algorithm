#문자열 집합
import sys
N,M = map(int, sys.stdin.readline().split())
cnt = 0
arr = [sys.stdin.readline().split() for _ in range(N)]
for _ in range(M):
  if sys.stdin.readline().split() in arr:
    cnt+=1

print(cnt)
