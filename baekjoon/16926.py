#배열 돌리기1
from collections import deque

N,M,R = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]

def rotate(r,c,h,w):
    global arr
    que = deque()

    for j in range(c,c+w):
        que.append(arr[r][j])
    for i in range(r+1,r+h):
        que.append(arr[i][c+w-1])
    for j in range(c+w-2,c,-1):
        que.append(arr[r+h-1][j])
    for i in range(r+h-1,r,-1):
        que.append(arr[i][c])

    que.rotate(-R)

    for j in range(c,c+w):
        arr[r][j] = que.popleft()
    for i in range(r+1,r+h):
        arr[i][c+w-1] = que.popleft()
    for j in range(c+w-2,c,-1):
        arr[r+h-1][j] = que.popleft()
    for i in range(r+h-1,r,-1):
        arr[i][c] = que.popleft()

r,c,h,w=0,0,N,M

while(h!=0 and w!=0):
    rotate(r,c,h,w)
    r += 1
    c += 1
    h -= 2
    w -= 2

for i in range(N):
    for j in range(M):
        print(arr[i][j], end=' ')
    print()
