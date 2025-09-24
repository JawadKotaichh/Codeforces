# """
# a : nubmer of mashbak
# b : nb to T-shirt he wants to dry
# infinite robes and each robe can hold up to x T-shirts
# every t-shirt needs 2 mashbak
# we can place two t-shirts at the overlapping point

# """

# t = int(input())
# while t != 0:
#     s = str(input()).split()
#     m = int(s[0])
#     tshirt = int(s[1])
#     x = int(s[2])
#     copy_T = tshirt
#     count_of_robes = 0
#     ok = True

#     if tshirt < x:
#         count_of_robes = 1
#         if tshirt + 1 > m:
#             ok = False
#     else:
#         count_of_robes = (tshirt // x) + 1

#         remaining_tshirts = tshirt
#         while remaining_tshirts != 0:
#             # print("m: ", m)
#             # print(f"remaining_tshirts: {remaining_tshirts}")
#             if m <= 0:
#                 ok = False
#                 break
#             if remaining_tshirts >= x:
#                 remaining_tshirts -= x
#                 m -= x + 1
#             else:
#                 m -= remaining_tshirts + 1
#                 if m < 0:
#                     ok = False
#                 # print("I eneter new m is: ", m)
#                 remaining_tshirts = 0
#                 break

#     if ok:
#         print("YES")
#     else:
#         print("NO")
#     t -= 1

t = int(input())
while t != 0:
    s = str(input()).split()
    m = int(s[0])
    tshirt = int(s[1])
    x = int(s[2])
    copy_T = tshirt
    count_of_robes = 0
    ok = True

    if tshirt < x:
        count_of_robes = 1
        if tshirt + 1 > m:
            ok = False
    else:
        count_of_robes = (tshirt // x) + 1
        # print("count of robes: ", count_of_robes)
        required_m = (count_of_robes - 1) * (x + 1)
        # print("required_m: ", required_m)

        m -= required_m
        # print("m now is: ", m)
        if m < 0:
            ok = False
        else:
            rem_tshirt = tshirt - ((count_of_robes - 1) * x)
            # print("rem is : ", rem_tshirt)
            if rem_tshirt != 0:
                if m < rem_tshirt + 1:
                    ok = False
            # print("m after is: ", m)

    if ok:
        print("YES")
    else:
        print("NO")
    t -= 1
