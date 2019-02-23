def solution(line):
    a, b = line.split('-')
    a, b = a[::-1], b[::-1]
    flag = 0
    result = ""
    for i in range(len(a)):
        if i >= len(b) and not flag:
            result += a[i:]
            break
        da = int(a[i])
        db = int(b[i]) + flag if i < len(b) else flag
        flag = 0
        d = da - db
        if d < 0:
            d += 10
            flag = 1
        result += str(d)
    result = result[::-1]
    result = result.lstrip('0')
    if result == '':
        result = '0'
    return result


if __name__ == "__main__":
    line = input()
    print(solution(line))
