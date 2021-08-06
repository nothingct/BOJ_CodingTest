from collections import deque
import sys
input = sys.stdin.readline
def bfs(start):
  q= deque()
  q.append(start)
  color[start]=1 
  
  while q:
    x= q.popleft()
    for y in g[x]:
      if color[y] == 0:
        color[y]=3-color[x]
        q.append(y)
      elif color[y]== color[x]:
        return 0
  return 1

t=int(input())
for _ in range(t):
  n,m=map(int,input().split()) #정점 , 간선 
  g= [[] for _ in range(n+1)]
  for _ in range(m):
    u,v = map(int,input().split())
    g[u].append(v)
    g[v].append(u)
    
  color = [0]*(n+1)
  flag=True
  for i in range(1,n+1):
    if color[i]== 0 : 
      ret= bfs(i)
      if not ret :
        flag=False
        break
  if flag:
    print("YES")
  else: 
    print("NO")