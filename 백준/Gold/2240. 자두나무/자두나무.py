T, W = map(int, input().split())
jadoo = [int(input()) for _ in range(T)]

def max_jadoo(site):
  dp = [[0]*(W+1) for _ in range(T+1)]

  for i in range(T):
    for j in range(W+1):
      if (jadoo[i]+j+site)%2 == 0:
        dp[i][j] += 1

    dp[i+1][0] = dp[i][0]
    for j in range(1, W+1):
      dp[i+1][j] = max(dp[i][j-1], dp[i][j])

  return max(dp[T-1])

# print(max(max_jadoo(2), max_jadoo(1)))
print(max_jadoo(1))