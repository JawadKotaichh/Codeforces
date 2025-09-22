from collections import Counter


def can_form_palindrome_by_rearranging(s: str) -> bool:
    freq = Counter(s)
    odd = sum(v % 2 for v in freq.values())
    return odd <= 1


def solve(a, n, k):
    answer = 0
    counts = {}
    for word in a:
        sorted_word = key = "".join(sorted(word))
        if sorted_word not in counts:
            counts[sorted_word] = 1
        else:
            counts[sorted_word] += 1
    odds = []
    for key in counts:
        if counts[key] % 2 == 0:
            answer += counts[key] * k
        else:
            answer += (counts[key] - 1) * k
            odds.append(key)
    for odd_word in odds:
        if can_form_palindrome_by_rearranging(odd_word):
            answer += k
            break
    return answer


t = int(input())
while t != 0:
    s = str(input()).split()
    n = int(s[0])
    k = int(s[1])
    a = []
    for i in range(n):
        s1 = str(input())
        a.append(s1)
    print(solve(a, n, k))
    t -= 1
