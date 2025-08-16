def equal_stacks(h1, h2, h3):
    # Reverse stacks to pop from "top" easily
    s1, s2, s3 = map(list, (reversed(h1), reversed(h2), reversed(h3)))

    # Precompute cumulative heights
    def cumulative(stack):
        total = 0
        cum = []
        for val in stack:
            total += val
            cum.append(total)
        return set(cum)

    set1, set2, set3 = cumulative(s1), cumulative(s2), cumulative(s3)

    # Find intersection (common heights)
    common = set1 & set2 & set3
    return max(common) if common else 0


if __name__ == "__main__":
    n1, n2, n3 = map(int, input().split())
    h1 = list(map(int, input().split()))
    h2 = list(map(int, input().split()))
    h3 = list(map(int, input().split()))

    print(equal_stacks(h1, h2, h3))
