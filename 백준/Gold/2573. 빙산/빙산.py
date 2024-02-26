import sys
from copy import deepcopy

N, M = map(int, input().split())
map = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

ans = 0

visit = [[0]*M for _ in range(N)]

def search(start_x, start_y):
  queue = []

  queue.append([start_x, start_y])
  visit[start_x][start_y] = 1

  while len(queue) != 0:
    x, y = queue.pop()
    for i in range(4):
      nx = x+dx[i]
      ny = y+dy[i]

      if nx < 0 or ny < 0 or nx >= N or ny >= M:
        continue
      if visit[nx][ny] != 0 or map[nx][ny] == 0:
        continue

      queue.append([nx, ny])
      visit[nx][ny] = 1

def next():
  now = deepcopy(map)
  for x in range(N):
    for y in range(M):
      if now[x][y] == 0:
        continue
        
      count = 0
      for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]

        if nx < 0 or ny < 0 or nx >= N or ny >= M:
          continue

        if now[nx][ny] == 0:
          count += 1

      map[x][y] = max(map[x][y]-count, 0)

year = 0
while sum(sum(line) for line in map) > 0: # 남아있는 빙산이 있을때까지
  visit = [[0]*M for _ in range(N)]

  ice = []

  for x in range(N):
    for y in range(M):
      if map[x][y] != 0 and visit[x][y] == 0:
        search(x, y)
        ice.append([x,y])
        
  if len(ice) >= 2:
    ans = year
    break

  next()
  year += 1

print(ans)