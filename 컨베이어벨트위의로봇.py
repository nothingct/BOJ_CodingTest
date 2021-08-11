n,k = map(int,input().split())
a=list(map(int,input().split()))
box = [False]*(2*n)
zeroCnt=0
timePassed=1
while True:
  a= a[-1:]+a[:-1]
  box=box[-1:]+box[:-1]
  if box[n-1] : box[n-1]=False
  for i in range(n-2,-1,-1):
    if box[i] : 
      if not box[i+1] and a[i+1]>0:
        box[i+1]=True
        box[i]=False
        a[i+1]-=1
        if a[i+1]==0: zeroCnt+=1
  if box[n-1]: box[n-1]=False
  if a[0] > 0 : 
    box[0]=True
    a[0]-=1
    if a[0]==0: zeroCnt+=1
  if zeroCnt>=k:
    print(timePassed)
    break
  timePassed+=1