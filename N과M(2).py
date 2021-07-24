
N, M = map(int, input().split())
perm = [0] * M  # 출력 내용


def solve(len, start):
    if len == M:  # 탈출 조건
      print(' '.join(map(str, perm)))  # list를 str으로 합쳐 출력
      return
    for i in range(start, N+1):  # 탐사 check 하면서
      perm[len] = i  # 탐사 내용
      solve(len+1, i+1)  # 깊이 우선 탐색


solve(0, 1)
