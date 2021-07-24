import sys
n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
perm = [0] * m


def makePermutations(len, start):
  if len == m:
    sys.stdout.write(' '.join(map(str, perm))+'\n')
    return

  for i in range(start, n):
    perm[len] = arr[i]
    makePermutations(len+1, i)


makePermutations(0, 0)
