# coding: utf-8
# created by deng on 2018-12-19


def solution(line):
    a, b = map(int, line.split())
    return str(a + b)


def main():
    line = input()
    print(solution(line))
    pass


if __name__ == '__main__':
    main()
