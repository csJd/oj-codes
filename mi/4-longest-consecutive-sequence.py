def solution(line):
    arr = map(int, line.split(','))
    longest_dict = dict()
    max_length = 0
    for num in arr:
        if num in longest_dict:
            continue
        left_length = 0 if num - 1 not in longest_dict \
            else longest_dict[num - 1]
        right_length = 0 if num + 1 not in longest_dict \
            else longest_dict[num + 1]
        longest_dict[num] = left_length + 1 + right_length
        if num - left_length in longest_dict:
            longest_dict[num - left_length] = longest_dict[num]
        if num + right_length in longest_dict:
            longest_dict[num + right_length] = longest_dict[num]
        if longest_dict[num] > max_length:
            max_length = longest_dict[num]
    return max_length


if __name__ == "__main__":
    line = input()
    print(solution(line))
