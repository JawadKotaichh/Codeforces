"""
 5 1 3 4 2 6

 1 2 3 4 5 6
 1 4 2 3 0 5

1

"""

import sys


def main():
    data = sys.stdin.readline().strip().split()
    if not data:
        return
    n, k = map(int, data)
    a = list(map(int, sys.stdin.readline().strip().split()))
    assert len(a) == n

    used = [False] * (n + 1)

    def pick(x):
        start = 1 if x == 1 else 2
        for i in range(start, n + 1, x):
            if not used[i]:
                return i
        return 1

    for _ in range(k):
        line = sys.stdin.readline()
        if not line:
            return
        x = int(line.strip())

        i = pick(x)
        print(i)
        sys.stdout.flush()
        verdict_line = sys.stdin.readline()
        if not verdict_line:
            return
        ok = verdict_line.strip()
        if ok == "0":
            return
        used[i] = True


if __name__ == "__main__":
    main()
