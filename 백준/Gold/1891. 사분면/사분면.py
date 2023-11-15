d, number = map(int, input().split())
dx, dy = map(int, input().split())

div = [pow(2, d-i) for i in range(1, d+1)]
section = [0, [1, 1], [0, 1], [0, 0], [1, 0]]

def get_xy(num, depth):
  if depth == d:
    return 0, 0

  ch = int(num[depth])
  dd = div[depth]

  nx, ny = get_xy(num, depth+1)
  
  return dd*section[ch][0]+nx, dd*section[ch][1]+ny

def get_str(x, y, depth):
  if depth == d:
    return ""

  dd = div[depth]
  ch = ""
  
  if x >= dd and y >= dd:
    ch = "1"
  elif x < dd and y >= dd:
    ch = "2"
  elif x < dd and y < dd:
    ch = "3"
  elif x >= dd and y < dd:
    ch = "4"
    
  return ch + get_str(x%dd, y%dd, depth+1)

x, y = get_xy(str(number), 0)

if x+dx < 0 or x+dx >= pow(2, d) or y+dy < 0 or y+dy >= pow(2, d):
  answer = -1
else:
  answer = get_str(x+dx, y+dy, 0)
print(answer)