N, S = map(int, input().split())
num = list(map(int, input().split()))


def solve(num, idx, sum):
  if idx == N:
    return 0

  ans = 0

  if sum + num[idx] == S:
    ans += 1

  ans += solve(num, idx + 1, sum)
  ans += solve(num, idx + 1, sum + num[idx])

  return ans


answer = solve(num, 0, 0)
print(answer)
