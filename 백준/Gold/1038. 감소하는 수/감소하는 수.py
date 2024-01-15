N = int(input())

reduce_num = []


def append_num(num):
  last = num[-1]
  for i in range(int(last)):
    temp = num + str(i)
    reduce_num.append(int(temp))
    append_num(temp)


for i in range(10):
  reduce_num.append(int(i))
  append_num(str(i))

reduce_num.sort()

answer = -1

if N < len(reduce_num):
  answer = reduce_num[N]

print(answer)