import sys
n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

perm = [0] * m


def makePermutations(len):
    if len == m:
        sys.stdout.write(' '.join(map(str, perm))+'\n')
        return

    for i in range(n):
        perm[len] = arr[i]
        makePermutations(len+1)


makePermutations(0)
