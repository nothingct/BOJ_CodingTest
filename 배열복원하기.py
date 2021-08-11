h,w,x,y = map(int,input().split())
b=[list(map(int,input().split())) for _ in range(h+x)]

for i in range(h):
  for j in range(w): 
    b[i+x][j+y]-=b[i][j]

for i in range(h):
  #b배열의 i행(b[i]:1차원 배열)을 0~w-1열 까지 출력
  print(*b[i][:w])