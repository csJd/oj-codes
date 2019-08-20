"""
zai lai yi bian
iaz ial yi bian
"""


def main():
    words = input().split()
    for i in range(len(words)):
        if len(words[i]) % 2 == 1:
            words[i] = words[i][::-1]
    print(" ".join(words))


if __name__ == "__main__":
    main()
