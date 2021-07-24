import sys
n,m = map(int,input().split())
arr= list(map(int,input().split()))
arr.sort()

visited = [False] * n
perm = [0] * m

def makePermutations(len):
  if len == m:
    sys.stdout.write(' '.join(map(str,perm))+'\n')
    return
  
  for i in range(n):
    if visited[i] == False:
      visited[i] = True
      perm[len] = arr[i]
      makePermutations(len+1)
      visited[i] = False
makePermutations(0)