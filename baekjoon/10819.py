# 차이를 최대로
from itertools import permutations

N = int(input())
numbers = list(map(int, input().split()))

answer = 0
for per in permutations(numbers,N):
  temp = 0
  for i in range(N-1):
    temp += abs(per[i+1]-per[i])
  if answer < temp:
    answer = temp

print(answer)
