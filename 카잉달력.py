t = int(input())
for _ in range(t):
  m,n,x,y = map(int,input().split())
  isPossible= False
  x-=1
  y-=1
  for year in range(x,m*n,m):
    cur_y = year%n
    if cur_y == y :
      isPossible= True
      print(year+1)
      break
  if(isPossible == False):
    print(-1)
