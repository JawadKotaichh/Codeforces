import sys
from collections import deque

MOD = 1_000_000_007
input = sys.stdin.readline


def main():
    s = input().split()
    n = int(s[0])
    m = int(s[1])
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        if a == b:
            print(0)
            return
        adj[a].append(b)
        adj[b].append(a)

    color = [-1] * (n + 1)
    components = 0

    for start in range(1, n + 1):
        if color[start] != -1:
            continue
        components += 1
        color[start] = 0
        q = deque([start])
        while q:
            u = q.popleft()
            for v in adj[u]:
                if color[v] == -1:
                    color[v] = 1 - color[u]
                    q.append(v)
                elif color[v] == color[u]:
                    print(0)
                    return

    print(pow(2, components, MOD))


if __name__ == "__main__":
    main()
