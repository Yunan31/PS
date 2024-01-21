n = int(input())
wines = [int(input()) for _ in range(n)]

DP = [[0]*3 for _ in range(n+1)]

for i in range(n):
  for drink in range(2):
    DP[i+1][drink+1] = DP[i][drink] + wines[i]
  DP[i+1][0] = max(DP[i])
  
print(max(DP[n]))