#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int rank[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &rank[i]);
    }

    int m;
    scanf("%d", &m);
    int player[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    int unique[n];
    int uCount = 0;
    unique[uCount++] = rank[0];
    for (int i = 1; i < n; i++) {
        if (rank[i] != rank[i - 1]) {
            unique[uCount++] = rank[i];
        }
    }

    int pos = uCount - 1; // Start from the lowest rank
    for (int i = 0; i < m; i++) {
        while (pos >= 0 && player[i] >= unique[pos]) {
            pos--;
        }
        printf("%d\n", pos + 2);
    }

    return 0;
}
