# 수강신청
import sys
input = sys.stdin.readline

K,L = map(int,input().split())
arr={}
for i in range(L):
    stri=input()
    arr[stri.rstrip('\n')]=i

sarr = sorted(arr.items(), key=lambda item:item[1])

for key in sarr[:K]:
    print(key[0])
