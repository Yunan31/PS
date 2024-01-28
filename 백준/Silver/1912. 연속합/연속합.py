n = int(input())
number = list(map(int, input().split()))

sum = ans = number[0]

for i in range(1, n):
  sum += number[i]
  if sum <= number[i]:
    sum = number[i]
  ans = max(ans, sum)

print(ans)