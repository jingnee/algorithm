#수 복원하기
for i in range(int(input())):
  num = int(input())
  answer = 0
  n = 2

  while(n<=num):
    while(num%n==0):
      num = num//n
      answer = answer+1
  
    if answer!=0:
      print(n,answer)
    n = n+1
    answer = 0
