import sys

N = int(input())
map = [list(map(int, list(sys.stdin.readline().strip()))) for _ in range(N)]
visit = [[0]*N for _ in range(N)]

ans = 0
count = []

def search(start_x, start_y):
  dx = [-1, 1, 0, 0]
  dy = [0, 0, -1, 1]

  queue = []
  count = 1

  queue.append([start_x, start_y])
  visit[start_x][start_y] = 1

  while len(queue) != 0:
    x, y = queue.pop()
    for i in range(4):
      nx = x+dx[i]
      ny = y+dy[i]

      if nx < 0 or ny < 0 or nx >= N or ny >= N:
        continue
      if visit[nx][ny] != 0 or map[nx][ny] == 0:
        continue

      queue.append([nx, ny])
      visit[nx][ny] = 1
      count += 1

  return count

for i in range(N):
  for j in range(N):
    if visit[i][j] == 0 and map[i][j] == 1:
      ans += 1
      count.append(search(i, j))

print(ans)
for cnt in sorted(count):
  print(cnt)


      