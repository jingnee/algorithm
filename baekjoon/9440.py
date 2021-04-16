# 숫자 더하기
tens=[1,10,100,1000,10000,100000,1000000]

while True:
  numbers = list(map(int,input().split()))
  if numbers[0] == 0:
    break
  N = numbers[0]
  numbers = numbers[1:]
  numbers.sort()

  # 제일 첫번째 수가 0이면 위치 바꿔줘
  if numbers[0]==0:
    idx=1
    while(numbers[idx]==0):
      idx += 1
    numbers[0]=numbers[idx]
    numbers[idx]=0
  # 두번째 숫자도 0이 아니어야함
  if numbers[1]==0:
    while(numbers[idx]==0):
      idx += 1
    numbers[1]=numbers[idx]
    numbers[idx]=0

  half = int(len(numbers)//2)
  ans = 0
  numbers = numbers[::-1]
  for i in range(len(numbers)):
    ans += numbers[i]*tens[(i//2)]
  print(ans)
