#include <stdio.h>
#include <string.h>

// Function to calculate the sum of digits of a number
long sumDigits(long num) {
    long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Recursive function to get super digit
long super_digit(long num) {
    if (num < 10) return num; // base case: single digit
    return super_digit(sumDigits(num));
}

int main() {
    char n[100001];
    long k;
    scanf("%s %ld", n, &k);

    // Step 1: Sum digits of n
    long initial_sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        initial_sum += n[i] - '0';
    }

    // Step 2: Multiply by k
    long total = initial_sum * k;

    // Step 3: Calculate super digit
    printf("%ld\n", super_digit(total));

    return 0;
}

