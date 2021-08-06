import sys
from collections import deque


def BFS(N):
    queue = deque()
    queue.append(N)

    distance[N] = 0
    visited[N] = 1

    while queue:
        curr = queue.popleft()

        for next in (curr + 1, curr - 1, curr * 2):
            if 0 <= next < 100001:
                if distance[next] == -1:
                    distance[next] = distance[curr] + 1
                    visited[next] = visited[curr]
                    queue.append(next)

                elif distance[next] == distance[curr] + 1:
                    visited[next] += visited[curr]


N, K = map(int, sys.stdin.readline().split())
distance = [-1 for _ in range(100001)]
visited = [0 for _ in range(100001)]

BFS(N)

print(distance[K])
print(visited[K])
