n,m = map(int,input().split())
a= [list(map(int,input().split())) for _ in range(n)]
ans=n*m*2
for i in range(n):
  cnt=a[i][0]
  for j in range(1,m):
    if a[i][j]>a[i][j-1] : cnt+=(a[i][j]-a[i][j-1])
  ans+=cnt
  cnt =a[i][m-1] 
  for j in range(m-2,-1,-1):
    if a[i][j]> a[i][j+1] : cnt+=(a[i][j]-a[i][j+1])
  ans+=cnt

for j in range(m):
  cnt = a[0][j]
  for i in range(1,n):
    if a[i][j] > a[i-1][j] : cnt+=(a[i][j]-a[i-1][j])
  ans+=cnt
  cnt=a[n-1][j]
  for i in range(n-2,-1,-1):
    if a[i][j] > a[i+1][j] : cnt+=(a[i][j]-a[i+1][j])
  ans+=cnt
print(ans)