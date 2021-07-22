MAX = 1000000
check = [False]*(MAX+1)
prime=[]
for i in range(2,MAX+1):
  if not check[i]:
    prime.append(i)
    j= i+i
    while j<=MAX:
      check[j] = True
      j+=i
prime = prime[1:] # prime[0] 은 2 니까 지운다.
while True:
  n=int(input())
  if n== 0 : break
  for p in prime:
    if check[n-p] == False : 
      print("{0} = {1} + {2}".format(n,p,n-p))
      break
      