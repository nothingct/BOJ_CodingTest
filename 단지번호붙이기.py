from collections import deque

n=int(input())
g=[list(map(int,list(input()))) for _ in range(n)]
c=[[False]*n for _ in range(n)]
numOfHouse = []
dx=(-1,1,0,0)
dy=(0,0,-1,1)

def bfs(sx,sy):
  c[sx][sy]= True
  q= deque()
  q.append((sx,sy))
  cnt=1
  while q:
    x,y= q.popleft()
    for i in range(4):
      nx=x+dx[i]
      ny=y+dy[i]
      if nx<0 or nx>=n or ny<0 or ny>=n: continue
      if g[nx][ny]==0 : continue
      if c[nx][ny]: continue
      c[nx][ny]=True
      cnt+=1
      q.append((nx,ny))
  return cnt

for i in range(n):
  for j in range(n):
    if g[i][j] == 1 and c[i][j]==False :
      ret=bfs(i,j)
      numOfHouse.append(ret)
numOfHouse.sort()

print(len(numOfHouse))
for i in range(len(numOfHouse)):
  print(numOfHouse[i])
      
      