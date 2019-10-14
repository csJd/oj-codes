def compareVersion(version1, version2):
    list1 = version1.split('.')
    list2 = version2.split('.')

    length = max(len(list1), len(list2))
    for i in range(length):
        v1 = 0 if i >= len(list1) else int(list1[i])
        v2 = 0 if i >= len(list2) else int(list2[i])
        if v1 != v2:
            return 1 if v1 > v2 else -1
    else:
        return 0


v1, v2 = input().split()
print(compareVersion(v1, v2))
