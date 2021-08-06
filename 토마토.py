from collections import deque
import sys

dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]
TowaMasiTensi = 0
ans=0

def bfs():
  global ans
  while q:
      x, y, z = q.popleft()
      ans=c[x][y][z]
      for i in range(6):
          nx = x + dx[i]
          ny = y + dy[i]
          nz = z + dz[i]
          if 0 <= nx < k and 0 <= ny < n and 0 <= nz < m:
              if a[nx][ny][nz] == 0 and c[nx][ny][nz] == 0:
                  q.append([nx, ny, nz])
                  a[nx][ny][nz] = 1
                  c[nx][ny][nz] = c[x][y][z] + 1

m, n, k = map(int, input().split())
a = [[list(map(int, input().split())) for _ in range(n)] for _ in range(k)]
c = [[[0]*m for _ in range(n)] for _ in range(k)]
q = deque()

for i in range(k):
    for j in range(n):
        for l in range(m):
            if a[i][j][l] == 1 and c[i][j][l] == 0:
              q.append([i, j, l])
            if a[i][j][l] == 0 :
              TowaMasiTensi+=1
if(TowaMasiTensi==0):
  print(0)
  sys.exit()

bfs()
if(TowaMasiTensi > 0 ):
  print(-1)
else:
  print(ans)

