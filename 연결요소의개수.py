from collections import deque
n,m = map(int,input().split())
check= [False]*(n+1)
g=[[] for _ in range(n+1)]

for _ in range(m):
  u,v = map(int,input().split())
  g[u].append(v) 
  g[v].append(u)

def bfs(start):
  global check
  q=deque()
  check[start] =True
  q.append(start)
  while q: 
    x= q.popleft()
    for y in g[x]:
      if not check[y]:
        check[y] =True
        q.append(y)
ans = 0
for i in range(1,n+1):
  if not check[i] :
    ans+=1
    bfs(i)
print(ans)