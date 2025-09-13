def build_sol0(max_len: int):
    sol0 = [None] * (max_len + 1)
    sol0[0] = None
    pow10 = 1
    for i in range(1, max_len + 1):
        sol0[i] = 9 * pow10 * i
        pow10 *= 10
    return sol0


def build_pref(sol0):
    pref = [0] * len(sol0)
    run = 0
    for i in range(1, len(sol0)):
        run += sol0[i]
        pref[i] = run
    return pref


def digits_up_to(n: int, pref):
    if n <= 0:
        return 0
    d = len(str(n))
    base = 10 ** (d - 1)
    return pref[d - 1] + (n - base + 1) * d


def find_number_and_digit(k: int, pref):
    lo, hi = 1, 1
    while digits_up_to(hi, pref) < k:
        hi <<= 1
    while lo < hi:
        mid = (lo + hi) // 2
        if digits_up_to(mid, pref) >= k:
            hi = mid
        else:
            lo = mid + 1
    n = lo

    prev = digits_up_to(n - 1, pref)
    idx1 = k - prev
    return n, idx1


def build_sol1(max_len: int):
    sol1 = [0] * (max_len + 1)
    sol1[0] = 0
    if max_len >= 1:
        sol1[1] = 1
    running_sum = sol1[1] if max_len >= 1 else 0  # sum_{j=1..i-1} sol1[j]
    pow10 = 10  # 10^(i-1), starting at i=2
    for i in range(2, max_len + 1):
        sol1[i] = running_sum * 9 + pow10
        running_sum += sol1[i]
        pow10 *= 10
    return sol1


def compute_res(num: int, pref1):
    d = str(num)
    D = len(d)
    # Precompute powers of 10 up to D
    pow10 = [1] * (D + 1)
    for t in range(1, D + 1):
        pow10[t] = pow10[t - 1] * 10

    res = 0

    # First double loop     # i = 1..9
    for j in range(0, D):
        for dig in range(1, 10):  # j = 0..D-1
            x = D - 1 - j
            dj = int(d[j])
            res += (pref1[x] * dj + pow10[x] * (1 if dig < dj else 0)) * dig

    # Second loop
    for j in range(0, D - 1):  # j = 0..D-2
        left_digit = int(d[j])
        tail = int(d[j + 1 :]) + 1 if j + 1 < D else 0
        res += tail * left_digit

    # Final add
    res += int(d[-1])

    return res


sol0 = build_sol0(16)
pref = build_pref(sol0)
sol1 = build_sol1(16)
pref1 = build_pref(sol1)
for _ in range(int(input())):
    k = int(input())
    S, p = find_number_and_digit(k, pref)
    res = compute_res(S, pref1)
    res -= sum([int(i) for i in str(S)[p:]])

    print(res)
