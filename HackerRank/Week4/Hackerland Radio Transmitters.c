#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int hackerlandRadioTransmitters(int x[], int n, int k) {
    qsort(x, n, sizeof(int), compare);
    int transmitters = 0;
    int i = 0;

    while (i < n) {
        transmitters++;

        // Step 1: Go as far right as possible within range k
        int loc = x[i] + k;
        while (i < n && x[i] <= loc) {
            i++;
        }

        // Step 2: Place transmitter at the farthest house in this range
        int place = x[i - 1] + k;

        // Step 3: Skip all houses covered by this transmitter
        while (i < n && x[i] <= place) {
            i++;
        }
    }

    return transmitters;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("%d\n", hackerlandRadioTransmitters(x, n, k));
    return 0;
}
