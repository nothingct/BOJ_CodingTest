CUR_POS =100
MAX=500000
brokenNum = [False]* 10

n= int(input())
m= int(input())
if m > 0:
  a = list(map(int,input().split()))
else : 
  a = []
for x in a:
  brokenNum[x] = True;


def isPossible(x):
  if x == 0:
    if brokenNum[x]:
      return 0
    else:
      return 1
  cnt = 0
  while(x > 0):
    num = x % 10
    if brokenNum[num]:
      return 0
    cnt += 1
    x //= 10
  return cnt

ans = abs(CUR_POS-n)
for x in range(MAX*2 + 1):
  cnt = isPossible(x);
  if cnt == 0:
    continue
  cnt += abs(x-n)
  ans = min(ans,cnt)
print(ans)
