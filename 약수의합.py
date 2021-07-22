MAX = 1000000
f = [1] * (MAX+1)
g = [0]* (MAX+1)

for i in range(2,MAX+1):
  j=1
  while i*j <=MAX:
    f[i*j] += i
    j+=1
for i in range(1,MAX+1):
  g[i] = g[i-1]+f[i]
t= int(input())
ans = []
for _ in range(t):
  n= int(input())
  ans.append(g[n])
print('\n'.join(map(str,ans))+'\n') 
