#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    else if (x > y) return 1;
    else return 0;
}

int maxmin(int k, int a[], int n) {
    qsort(a, n, sizeof(int), comp);
    int min = a[k-1] - a[0];
    for (int i = 1; i <= n - k; i++) {
        int d = a[i + k - 1] - a[i];
        if (d < min) {
            min = d;
        }
    }
    return min;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int r = maxmin(k, a, n);
    printf("%d\n", r);
    return 0;
}
