def sort(n,l,r,a,b):
    a=a[l-1:r]
    b=b[l-1:r]
    da={}
    db={}
    answer=0
    for i in range(r-l+1):
        if a[i] not in da:
            da[a[i]]=1
        else:
            da[a[i]]+=1
        
        if b[i] not in db:
            db[b[i]]=1
        else:
            db[b[i]]+=1

    for j in db:
        if j not in da:
            answer+=db[j]
        elif j in da and da[j]<db[j]:
            answer=answer+db[j]-da[j]
        else:
            continue
    return answer

t=int(input())
for i in range(t):
    s1=str(input()).split()
    n=int(s1[0])
    q=int(s1[1])
    a=str(input())
    b=str(input())
    for j in range(q):
        s2=str(input()).split()
        l=int(s2[0])
        r=int(s2[1])
        print(sort(n,l,r,a,b))


# from collections import defaultdict

# def precompute_frequency(s):
#     n = len(s)
#     freq = [defaultdict(int) for _ in range(n+1)]
#     for i in range(n):
#         freq[i+1] = freq[i].copy()
#         freq[i+1][s[i]] += 1
#     return freq

# def count_changes(freq_a, freq_b, l, r):
#     count = 0
#     for char in freq_b[r]:
#         count += max(0, freq_b[r][char] - freq_a[r].get(char, 0))
#     return count

# def solve():
#     t = int(input())
#     for _ in range(t):
#         n, q = map(int, input().split())
#         a = input()
#         b = input()
#         freq_a = precompute_frequency(a)
#         freq_b = precompute_frequency(b)
#         for _ in range(q):
#             l, r = map(int, input().split())
#             print(count_changes(freq_a, freq_b, l, r))

# if __name__ == "__main__":
#     solve()
