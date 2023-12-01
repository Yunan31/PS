n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
DP = [99999]*10005
DP[k] = 0
for now in range(k, 0, -1):
  for coin in coins:
    if now - coin < 0:
      continue
    DP[now-coin] = min(DP[now]+1, DP[now-coin])

if DP[0] != 99999:
  print(DP[0])
else:
  print(-1)