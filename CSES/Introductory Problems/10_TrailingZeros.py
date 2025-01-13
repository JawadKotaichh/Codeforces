def count_trailing_zeros(n):
    count = 0
    power_of_5 = 5
    while n >= power_of_5:
        count += n // power_of_5
        power_of_5 *= 5
    return count

n=int(input())
print(count_trailing_zeros(n))