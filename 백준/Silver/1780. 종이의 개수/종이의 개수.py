N = int(input())
paper = [list(map(int, input().split())) for _ in range(N)]
answer = {-1:0, 0:0, 1:0}

def rec(paper, size):
  if size == 1 or sum(paper, []).count(paper[0][0]) == size*size:
    answer[paper[0][0]] += 1
    return

  d = size//3
  for i in range(3):
    for j in range(3):
      rec([row[j*d:(j+1)*d] for row in paper[i*d:(i+1)*d]], d)
    
rec(paper, N)

print(f'{answer[-1]}\n{answer[0]}\n{answer[1]}')
