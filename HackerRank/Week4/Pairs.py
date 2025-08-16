def pairs(k, arr):
    # Convert list to a set for quick lookup
    values = set(arr)
    count = 0

    # For each number, check if num + k exists in the set
    for num in arr:
        if num + k in values:
            count += 1
    return count


if __name__ == "__main__":
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(pairs(k, arr))
