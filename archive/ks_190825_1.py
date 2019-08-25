"""
3
10
V_0
V_1
V_2
P_3
P_4
P_5
V_6
P_7
V_8
V_9

8
V_0
V_1
V_2
P_3
V_6
V_8
P_4
V_9

2
10
V_0
V_1
V_2
P_3
P_4
P_5
V_6
P_7
V_8
V_9
"""
from collections import deque


def main():
    n = int(input())
    m = int(input())

    cnt = n-1
    ans = list()
    queue = deque()

    for i in range(m):
        s = input()
        if s.startswith('P'):
            queue.append(s)
        else:
            while queue and cnt >= n-1:
                p = queue.popleft()
                ans.append(p)
                cnt = 0
            ans.append(s)
            cnt += 1

    while queue and cnt >= n-1:
        p = queue.popleft()
        ans.append(p)
        cnt = 0

    print(len(ans))
    for x in ans:
        print(x)


if __name__ == "__main__":
    main()
