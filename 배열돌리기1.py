n,m,r = map(int,input().split())
a=[list(map(int,input().split())) for _ in range(n)]
groups = [] 
groupn = min(n,m)//2
for k in range(groupn):
  group = []
  #좌상단-> 우상단
  for j in range(k,m-k):
    group.append(a[k][j])
  #우상단->우하단 
  for i in range(k+1,n-k-1):
    group.append(a[i][m-k-1])
  #우하단->좌하단
  for j in range(m-k-1,k,-1):
    group.append(a[n-k-1][j])
  #좌하단->좌상단 
  for i in range(n-k-1,k,-1):
    group.append(a[i][k])
  groups.append(group)

for k in range(groupn):
  group = groups[k]
  l = len(group)
  index= r % l
  #좌상단-> 우상단
  for j in range(k, m-k):
    a[k][j]=group[index]
    index= (index+1)%l
  #우상단->우하단
  for i in range(k+1, n-k-1):
    a[i][m-k-1]=group[index]
    index= (index+1)%l
  #우하단->좌하단
  for j in range(m-k-1, k, -1):
    a[n-k-1][j]=group[index]
    index= (index+1)%l
  #좌하단->좌상단
  for i in range(n-k-1, k, -1):
    a[i][k]=group[index]
    index=(index+1)%l

for row in a:
  print(' '.join(map(str,row)))