n = int(input())
wines = [int(input()) for _ in range(n)]

DP = [[0]*3 for _ in range(n+1)]

for i in range(n):
  DP[i+1][1] = DP[i][0] + wines[i]
  DP[i+1][2] = DP[i][1] + wines[i]
  DP[i+1][0] = max(DP[i])
  
print(max(DP[n]))