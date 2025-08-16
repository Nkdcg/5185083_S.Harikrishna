#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    int index;
} Pair;

int cmpAsc(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return (p1->value - p2->value);
}

int cmpDesc(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return (p2->value - p1->value);
}


int countSwaps(Pair *pairs, int n) {
    int *visited = (int *)calloc(n, sizeof(int));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || pairs[i].index == i)
            continue;

        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            j = pairs[j].index;
            cycle_size++;
        }
        if (cycle_size > 1)
            swaps += (cycle_size - 1);
    }

    free(visited);
    return swaps;
}

int lilysHomework(int *arr, int n) {
    Pair *pairsAsc = (Pair *)malloc(n * sizeof(Pair));
    Pair *pairsDesc = (Pair *)malloc(n * sizeof(Pair));

    for (int i = 0; i < n; i++) {
        pairsAsc[i].value = arr[i];
        pairsAsc[i].index = i;

        pairsDesc[i].value = arr[i];
        pairsDesc[i].index = i;
    }

    qsort(pairsAsc, n, sizeof(Pair), cmpAsc);
    qsort(pairsDesc, n, sizeof(Pair), cmpDesc);

       for (int i = 0; i < n; i++) {
        pairsAsc[i].index = pairsAsc[i].index;
        pairsDesc[i].index = pairsDesc[i].index;
    }

    int resAsc = countSwaps(pairsAsc, n);
    int resDesc = countSwaps(pairsDesc, n);

    free(pairsAsc);
    free(pairsDesc);

    return (resAsc < resDesc ? resAsc : resDesc);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", lilysHomework(arr, n));

    free(arr);
    return 0;
}
