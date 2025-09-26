n = int(input())
s1 = str(input()).split()
s2 = str(input()).split()
a = [int(s1[i]) for i in range(len(s1))]
b = [int(s2[i]) for i in range(len(s2))]
memo = {}


def f_bottum_up(a, b):
    memo_array = [[0 for j in range(3)] for k in range(len(a) + 1)]
    memo_array[len(a)][0] = 0
    memo_array[len(a)][1] = 0
    memo_array[len(a)][2] = 0
    i = len(a) - 1
    while i >= 0:
        memo_array[i][0] = max(b[i] + memo_array[i + 1][1], memo_array[i + 1][2])
        memo_array[i][1] = max(a[i] + memo_array[i + 1][0], memo_array[i + 1][2])
        memo_array[i][2] = max(
            a[i] + memo_array[i + 1][0],
            b[i] + memo_array[i + 1][1],
            memo_array[i + 1][2],
        )
        i -= 1
    return memo_array[0][2]


# def f(i, a, b, prev):
#     ans = 0
#     if i >= len(a):
#         return 0
#     if (i, prev) in memo:
#         return memo[(i, prev)]
#     if prev == 0:
#         ans = max(ans, b[i] + f(i + 1, a, b, 1))
#         ans = max(ans, f(i + 1, a, b, 2))
#     elif prev == 1:
#         ans = max(ans, a[i] + f(i + 1, a, b, 0))
#         ans = max(ans, f(i + 1, a, b, 2))
#     else:
#         ans = max(ans, a[i] + f(i + 1, a, b, 0))
#         ans = max(ans, b[i] + f(i + 1, a, b, 1))
#         ans = max(ans, f(i + 1, a, b, 2))
#     memo[(i, prev)] = ans
#     return ans


# print(f(0, a, b, 2))
print(f_bottum_up(a, b))
