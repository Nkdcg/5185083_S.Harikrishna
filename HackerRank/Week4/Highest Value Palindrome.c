#include <stdio.h>
#include <string.h>

char* highestValuePalindrome(char s[], int n, int k) {
    static char result[100005];
    int i, j;
    int changed[100005] = {0};  
    strcpy(result, s);

    // First pass: make palindrome
    int used = 0;
    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (result[i] != result[j]) {
            if (used == k) return "-1"; 
            if (result[i] > result[j]) result[j] = result[i];
            else result[i] = result[j];
            changed[i] = changed[j] = 1;
            used++;
        }
    }

    
    for (i = 0, j = n - 1; i <= j && used < k; i++, j--) {
        if (i == j) {
            // Middle element in odd length
            if (result[i] != '9' && used < k) {
                result[i] = '9';
                used++;
            }
        } else {
            if (result[i] != '9') {
                if (changed[i] || changed[j]) {
                    if (used < k) {
                        result[i] = result[j] = '9';
                        used++;
                    }
                } else {
                    if (used + 2 <= k) {
                        result[i] = result[j] = '9';
                        used += 2;
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    int n, k;
    char s[100005];

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    printf("%s\n", highestValuePalindrome(s, n, k));

    return 0;
}
