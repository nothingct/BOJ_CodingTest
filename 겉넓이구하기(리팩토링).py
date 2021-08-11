dx=[-1,1,0,0]
dy=[0,0,-1,1]

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
#테두리 채우기 for 계산단순화
a = [[0]*(m+2)] + [[0]+row+[0] for row in a] + [[0]*(m+2)]

ans = n*m*2
for x in range(1,n+1):
  for y in range(1,m+1):
    for d in range(4):
      nx,ny= x+dx[d],y+dy[d]
      if (a[x][y] - a[nx][ny]) > 0 : ans+= a[x][y]-a[nx][ny]
print(ans)
