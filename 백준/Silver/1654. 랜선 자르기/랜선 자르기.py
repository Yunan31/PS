K, N = map(int, input().split())
cable = [int(input()) for _ in range(K)]

def count(num):
  count = 0
  for c in cable:
    count += c//num
  return count

low = 1
high = max(cable)

while(low <= high):
  mid = (low + high)//2
  if(count(mid) < N):
    high = mid-1
  else:
    low = mid+1

print(high)