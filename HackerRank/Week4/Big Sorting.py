def big_sorting(numbers):
    # Sort primarily by length, then lexicographically
    return sorted(numbers, key=lambda x: (len(x), x))


if __name__ == "__main__":
    n = int(input().strip())
    numbers = [input().strip() for _ in range(n)]

    result = big_sorting(numbers)
    for num in result:
        print(num)
