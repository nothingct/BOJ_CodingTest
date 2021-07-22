def isPrime(n):
  if n < 2 : return False
  i=2
  while i*i <=n :
    if n % i == 0 : return False
    i+=1
  return True

t=int(input())
a=list(map(int,input().split()))
cnt=0
for num in a:
  if isPrime(num) == True: cnt+=1
print(cnt)