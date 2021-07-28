import sys
n,m = map(int,input().split())
a= [[False]* n for _ in range(n)]
g=[[] for _ in range(n)]
edges=[]
for _ in range(m):
  v1,v2 = map(int,input().split())
  edges.append((v1,v2)) 
  edges.append((v2,v1))
  
  a[v1][v2]= True 
  a[v2][v1]= True
  
  g[v1].append(v2)
  g[v2].append(v1)
m*=2
for i in range(m): 
  for j in range(m):
    A,B= edges[i]
    C,D= edges[j]
    if A==B or A==C or A==D or B==C or B==D or C==D : continue
    if not a[B][C] : continue
    for E in g[D]:
      if A==E or B==E or C==E or D==E : continue
      print(1)
      sys.exit(0)  
print(0)
  