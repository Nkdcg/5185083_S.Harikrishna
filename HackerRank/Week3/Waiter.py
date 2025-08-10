#!/bin/python3

import os

# Function to generate the first `n` prime numbers
def generate_primes(n):
    primes = []
    num = 2
    while len(primes) < n:
        is_prime = True
        for p in primes:
            if num % p == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)
        num += 1
    return primes

def waiter(number, q):
    result = []
    primes = generate_primes(q)  # Get the first q primes

    A = number[:]  # Initial stack A
    for i in range(q):
        prime = primes[i]
        B = []  # Stack to hold divisible numbers
        new_A = []  # Stack to hold non-divisible numbers

        # Pop from A and split into B or new_A
        while A:
            plate = A.pop()
            if plate % prime == 0:
                B.append(plate)
            else:
                new_A.append(plate)

        # Add plates from B to result in order popped
        while B:
            result.append(B.pop())

        # The new A becomes the stack for the next iteration
        A = new_A

    # After q iterations, append remaining plates in A
    while A:
        result.append(A.pop())

    return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])
    q = int(first_multiple_input[1])

    number = list(map(int, input().rstrip().split()))

    result = waiter(number, q)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
