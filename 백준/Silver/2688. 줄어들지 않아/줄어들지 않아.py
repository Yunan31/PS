T = int(input())
input = [int(input()) for _ in range(T)]

for i in range(T):
  size = input[i]
  DP = [[0]*10 for _ in range(size)]
  for k in range(10):
    DP[0][k] = 1

  for now in range(1, size):
    for k in range(10):
      DP[now][k] = sum(DP[now-1][:k+1])

  print(sum(DP[size-1]))