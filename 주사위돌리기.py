dx=[0,0,-1,1]
dy=[1,-1,0,0]
dice=[0]*7
n,m,x,y,k =map(int,input().split())
a= [list(map(int,input().split())) for _ in range(n)]
d= list(map(int,input().split()))
for i in range(k): 
  d[i]-=1
  nx= x+dx[d[i]]
  ny=y+dy[d[i]]
  if nx<0 or nx >= n or ny<0 or ny >=m : continue
  
  if d[i]==0: 
    temp= dice[1]
    dice[1] = dice[4]
    dice[4] = dice[6]
    dice[6] = dice[3]
    dice[3] = temp
  elif d[i]==1:
   temp = dice[1]
   dice[1] = dice[3]
   dice[3] = dice[6]
   dice[6] = dice[4]
   dice[4] = temp
  elif d[i]==2:
    temp=dice[1]
    dice[1] = dice[5]
    dice[5] = dice[6]
    dice[6] = dice[2]
    dice[2] = temp
  elif d[i]==3:
    temp=dice[1]
    dice[1] = dice[2]
    dice[2] = dice[6]
    dice[6] = dice[5]
    dice[5] = temp

  x,y=nx,ny
  if a[x][y]==0: a[x][y]=dice[6]
  else : 
    dice[6]=a[x][y]
    a[x][y]=0
  print(dice[1])
