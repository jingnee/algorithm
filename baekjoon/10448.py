#유레카 이론
arr = [n*(n+1)//2 for n in range(1,46)]
eureka = [0 for i in range(0,1001)]

for i in arr:
  for j in arr:
    for k in arr:
      if i+j+k <= 1000:
        eureka[i+j+k]=1

N = int(input())
for _ in range(N):
  print(eureka[int(input())])
