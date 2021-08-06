from collections import deque
n,m=map(int,input().split())
g=[list(map(int,list(input()))) for _ in range(n)]
c=[[0]*m for _ in range(n)]
dx=(-1,1,0,0)
dy=(0,0,-1,1)

def bfs(sx,sy):
  q=deque()
  q.append((sx,sy))
  c[sx][sy]=1
  while q:
    x,y= q.popleft()
    if x==n-1 and y==m-1 : break
    for i in range(4):
      nx,ny= x+dx[i],y+dy[i]
      if nx <0 or nx >=n or ny<0 or ny>=m: continue
      if g[nx][ny]==0 : continue
      if c[nx][ny]!=0 : continue 
      c[nx][ny]=c[x][y]+1
      q.append((nx,ny))
  return c[n-1][m-1]

print(bfs(0,0))