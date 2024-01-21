N = int(input())
MOD = 1000000007
DP = [0]*(1000001)
sum = 1

DP[1] = 2
DP[2] = 7

for i in range(N+1):
  if i < 3:
    continue
  DP[i] = (DP[i-1]*2 + DP[i-2]*3 + sum*2)%MOD
  sum += DP[i-2]%MOD

print(DP[N])