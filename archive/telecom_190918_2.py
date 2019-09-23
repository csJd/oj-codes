"""
ababa;ststs
>> True
"""


def main():
    sa, sb = input().split(';')
    la = len(sa)
    lb = len(sb)
    if la != lb:
        print("False")
        return

    trans_dict = dict()
    for i in range(la):
        if sa[i] in trans_dict:
            if sb[i] != trans_dict[sa[i]]:
                print("False")
                break
        else:
            trans_dict[sa[i]] = sb[i]
    else:
        print("True")


if __name__ == "__main__":
    main()
