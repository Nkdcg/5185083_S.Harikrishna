#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int n, int queries[][3], int q) {
    // Use long for large values
    long *arr = (long *)calloc(n + 2, sizeof(long));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return -1;
    }


    for (int i = 0; i < q; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a] += k;
        if (b + 1 <= n)
            arr[b + 1] -= k;
    }

 
    long maxVal = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        if (current > maxVal)
            maxVal = current;
    }

    free(arr);
    return maxVal;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int (*queries)[3] = malloc(m * sizeof *queries);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    printf("%ld\n", arrayManipulation(n, queries, m));

    free(queries);
    return 0;
}
