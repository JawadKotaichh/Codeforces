def count_bit_strings_mod(n):
    MOD = 10**9 + 7
    return pow(2, n, MOD)
n=int(input())
print(count_bit_strings_mod(n))
