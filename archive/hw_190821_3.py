"""
每个人都会在自己的所有群群发消息，消息发给一个人后最后能有多少人收到


Jack
3
Jack,Tom,Anny,Lucy
Tom,Danny
Jack,Lily

6
"""


def main():
    first = input()
    m = int(input())
    groups = []
    reciever = set()
    for i in range(m):
        groups.append(set(input().split(',')))

    queue = list()
    queue.append(first)
    vis = [False] * len(groups)
    while queue:
        name = queue.pop()
        for i, group in enumerate(groups):
            if not vis[i] and (name in group):
                vis[i] = True
                for x in group:
                    if x not in reciever:
                        queue.append(x)
                        reciever.add(x)
    print(len(reciever))


if __name__ == "__main__":
    main()
