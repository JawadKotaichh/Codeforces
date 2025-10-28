s = str(input())


def check(s):
    if len(s) < 26:
        return -1
    else:
        for i in range(len(s) - 25):
            found = {
                "A": 0,
                "B": 0,
                "C": 0,
                "D": 0,
                "E": 0,
                "F": 0,
                "G": 0,
                "H": 0,
                "I": 0,
                "J": 0,
                "K": 0,
                "L": 0,
                "M": 0,
                "N": 0,
                "O": 0,
                "P": 0,
                "Q": 0,
                "R": 0,
                "S": 0,
                "T": 0,
                "U": 0,
                "V": 0,
                "W": 0,
                "X": 0,
                "Y": 0,
                "Z": 0,
                "?": 0,
            }
            ans = []
            available = 0
            indexes_empty = []
            j = i
            count = 0
            already = 0
            while count < 26 and j < len(s):
                if s[j] == "?":
                    available += 1
                    indexes_empty.append(j)

                found[s[j]] += 1
                ans.append(s[j])
                j += 1
                count += 1

            empty_i = 0
            if len(ans) == 26:
                valid = True
                for t in found:
                    if t != "?" and found[t] > 1:
                        valid = False
                        break
                if not valid:
                    continue
                for t in found:
                    if t != "?" and found[t] == 1:
                        already += 1
                    elif found[t] == 0 and empty_i < len(indexes_empty):
                        ans[indexes_empty[empty_i] - i] = t
                        empty_i += 1
                        already += 1

                if already == 26:
                    slist = list(s)
                    slist[i : i + 26] = ans
                    for k in range(len(slist)):
                        if slist[k] == "?":
                            slist[k] = "A"
                    return "".join(slist)
        return -1


print(check(s))
