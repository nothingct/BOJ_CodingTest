import sys
n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
perm = [0]*m
results = []


def makePerms(len):
  if len == m:
    results.append(tuple(perm))
    return
  for i in range(n):
    perm[len] = arr[i]
    makePerms(len+1)


makePerms(0)
results = sorted(list(set(results)))
for p in results:
  sys.stdout.write(' '.join(map(str, p))+'\n')
