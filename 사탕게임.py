def countcol(i):  # i 번째 열 검사하기
    res = 1
    cnt = 1
    for k in range(n-1):
        if candy[k+1][i] == candy[k][i]:
            cnt += 1
            res = max(res, cnt)
        else:
            cnt = 1
    return res


def countraw(j):  # j 번째 행 검사하기
    res = 1
    cnt = 1
    for k in range(n-1):
        if candy[j][k+1] == candy[j][k]:
            cnt += 1
            res = max(res, cnt)
        else:
            cnt = 1
    return res


n = int(input())
candy = [list(input()) for _ in range(n)]

maxcandy = 0

for i in range(n):
    maxcandy = max(maxcandy, countcol(i), countraw(i))

for i in range(n):
    for j in range(n-1):
        candy[i][j+1], candy[i][j] = candy[i][j], candy[i][j+1]
        maxcandy = max(maxcandy, countraw(i), countcol(j), countcol(j+1))
        candy[i][j+1], candy[i][j] = candy[i][j], candy[i][j+1]

        candy[j+1][i], candy[j][i] = candy[j][i], candy[j+1][i]
        maxcandy = max(maxcandy, countraw(j), countraw(j+1), countcol(i))
        candy[j+1][i], candy[j][i] = candy[j][i], candy[j+1][i]

print(maxcandy)


def countcol(i):  # i 번째 열 검사하기
    res = 1
    cnt = 1
    for k in range(n-1):
        if candy[k+1][i] == candy[k][i]:
            cnt += 1
            res = max(res, cnt)
        else:
            cnt = 1
    return res


def countraw(j):  # j 번째 행 검사하기
    res = 1
    cnt = 1
    for k in range(n-1):
        if candy[j][k+1] == candy[j][k]:
            cnt += 1
            res = max(res, cnt)
        else:
            cnt = 1
    return res


n = int(input())
candy = [list(input()) for _ in range(n)]

maxcandy = 0

for i in range(n):
    maxcandy = max(maxcandy, countcol(i), countraw(i))

for i in range(n):
    for j in range(n-1):
        candy[i][j+1], candy[i][j] = candy[i][j], candy[i][j+1]
        maxcandy = max(maxcandy, countraw(i), countcol(j), countcol(j+1))
        candy[i][j+1], candy[i][j] = candy[i][j], candy[i][j+1]

        candy[j+1][i], candy[j][i] = candy[j][i], candy[j+1][i]
        maxcandy = max(maxcandy, countraw(j), countraw(j+1), countcol(i))
        candy[j+1][i], candy[j][i] = candy[j][i], candy[j+1][i]

print(maxcandy)
