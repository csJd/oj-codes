def main():
    nums = eval(input())
    sum = int(input())
    n = len(nums)

    for i in range(n):
        for j in range(i+1, n):
            if nums[i] + nums[j] == sum:
                print([i, j])
                return


if __name__ == "__main__":
    main()
