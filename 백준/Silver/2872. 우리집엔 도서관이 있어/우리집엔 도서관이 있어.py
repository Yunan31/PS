import sys

N = int(input())
book = [int(sys.stdin.readline()) for _ in range(N)]

max_val = max(book)
max_idx = book.index(max_val)

count = 0

for i in range(max_idx, -1, -1):
  if max_val == book[i]:
    max_val -= 1
    count += 1

print(N-count)