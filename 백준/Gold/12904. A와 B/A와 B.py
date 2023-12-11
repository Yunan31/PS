S = input()
T = input()

while len(S) != len(T):
  T = T[:len(T) - 1] if T[len(T) - 1] == 'A' else T[:len(T) - 1][::-1]

if S == T:
  print(1)
else:
  print(0)