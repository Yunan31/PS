N, H = map(int, input().split())
up = []
down = []

for i in range(N):
  if i%2 == 0:
    down.append(int(input()))
  else:
    up.append(int(input()))

up.sort()
down.sort()

def count(num, obstacle):
  low = 0
  high = len(obstacle)-1

  while low <= high:
    mid = (low+high)//2
    if obstacle[mid] >= num:
      high = mid-1
    else:
      low = mid+1

  return len(obstacle)-low

ans = N
ans_count = 0

for h in range(1, H+1):
  cnt = count(h, down) + count(H-h+1, up)
  if cnt < ans:
    ans = cnt
    ans_count = 1
  elif cnt == ans:
    ans_count += 1

print(ans, ans_count)