#include <stdio.h>
#include <stdlib.h>

int isPowerOfTwo(unsigned long long n) {
    return (n & (n - 1)) == 0; 
}

unsigned long long largestPowerOfTwoLessThan(unsigned long long n) {
    unsigned long long p = 1;
    while (p << 1 < n) {
        p <<= 1;
    }
    return p;
}

const char* counterGame(unsigned long long n) {
    int moves = 0;
    while (n > 1) {
        if (isPowerOfTwo(n)) {
            n >>= 1; // divide by 2
        } else {
            n -= largestPowerOfTwoLessThan(n);
        }
        moves++;
    }
    return (moves % 2 == 1) ? "Louise" : "Richard";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        printf("%s\n", counterGame(n));
    }
    return 0;
}
