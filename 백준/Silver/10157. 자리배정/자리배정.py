C, R = map(int, input().split())
K = int(input())

seat = [[0]*C for _ in range(R)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

x, y = 0, 0
now_seat = 1
i = 0
flag = 1

while now_seat < K:
  if(R*C < K):
    print(0)
    flag = 0
    break
    
  seat[x][y] = now_seat
  nx, ny = x+dx[i], y+dy[i]
  if nx < 0 or nx >= R or ny < 0 or ny >= C or seat[nx][ny] != 0:
    i += 1
    if i == 4:
      i = 0
    continue
  x, y = nx, ny
  now_seat += 1

if flag:
  print(y+1, x+1)