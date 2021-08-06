from collections import deque
n, k = map(int, input().split())
MAX = 200000
dist = [-1]*(MAX+1)

def bfs(s, e):
  q = deque()
  dist[s] = 0
  q.append(s)
  while q:
    now = q.popleft()
    if now == e:
      break
    if now*2 < MAX and dist[now*2] == -1:
        dist[now*2] = dist[now]
        q.appendleft(now*2)
    if now-1 >= 0 and dist[now-1] == -1:
        dist[now-1] = dist[now]+1
        q.append(now-1)
    if now + 1 < MAX and dist[now+1] == -1:
        dist[now+1] = dist[now]+1
        q.append(now+1)
  return dist[e]

print(bfs(n, k))
