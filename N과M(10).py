import sys
n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
visited = [False]*n
perm = [0]*m
results = []


def makePerms(len, start):
  if len == m:
    results.append(tuple(perm))
    return
  for i in range(start, n):
    if visited[i]:
      continue
    visited[i] = True
    perm[len] = arr[i]
    makePerms(len+1, i)
    visited[i] = False


makePerms(0, 0)
results = sorted(list(set(results)))
for p in results:
  sys.stdout.write(' '.join(map(str, p))+'\n')
