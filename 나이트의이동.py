from collections import deque 

dx=[-2,-1,1,2,2,1,-1,-2]
dy=[1,2,2,1,-1,-2,-2,-1]

t = int(input())
for _ in range(t):
  n=int(input())
  sx,sy = map(int,input().split())
  ex,ey = map(int,input().split())
  visited=[[-1]*n for _ in range(n)]
  q=deque()
  q.append((sx,sy))
  visited[sx][sy]=0
  while q:
    x,y = q.popleft()
    if x==ex and y==ey : 
      print(visited[x][y])
      break
    for i in range(8):
      nx = x+dx[i]
      ny= y+dy[i]
      if 0<=nx<n and 0<=ny<n : 
        if visited[nx][ny]==-1:
          visited[nx][ny]=visited[x][y]+1
          q.append((nx,ny))
  