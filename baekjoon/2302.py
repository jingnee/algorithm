#극장 좌석
N = int(input())
M = int(input())
vip = []
for i in range(M):
  num = int(input())
  vip.append(num)

dp = [1,1,2]
for i in range(3,41):
  dp.append(dp[i-1]+dp[i-2])

ans = 1
if M >= 1:
  idx = 0
  for i in range(0,M):
    ans = ans * dp[vip[i]-idx-1]
    idx = vip[i]
  ans = ans*dp[N-idx]
else:
  ans = dp[N]

print(ans)
