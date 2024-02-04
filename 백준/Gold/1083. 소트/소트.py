N = int(input())
arr = list(map(int, input().split()))
S = int(input())

sorted = sorted(arr, reverse=True)

for base in range(N):
  for target in range(N):
    if sorted[target] == arr[base]:
      break
      
    target_idx = arr.index(sorted[target])
    if target_idx-base <= S and target_idx > base:
      S -= target_idx-base
      arr.remove(sorted[target])
      arr.insert(base, sorted[target])
      break
      
for num in arr:
  print(num, end=' ')