import sys
input = sys.stdin.readline
output = sys.stdout.write # must be string
 
def hashing():
    n = int(input())
    arr_gen = (int(x) for x in input().split())
    visit = set()
    ans = 0
    for num in arr_gen:
        if num in visit:
            continue
 
        visit.add(num)
        ans += 1
 
    output(f"{ans}")
 
 
def sorting():
    n = int(input())
    arr = sorted(int(x) for x in input().split())
    ans = 1
    for i in range(1, n):
        if arr[i] != arr[i-1]:
            ans += 1
 
    output(f"{ans}")
 
 
# hashing()
sorting()