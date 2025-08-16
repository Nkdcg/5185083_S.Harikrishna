#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int front, rear;
} Deque;

Deque* createDeque(int n) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(n * sizeof(int));
    dq->front = dq->rear = 0;
    return dq;
}

int isEmpty(Deque* dq) {
    return dq->front == dq->rear;
}

void pushBack(Deque* dq, int val) {
    dq->data[dq->rear++] = val;
}

void popBack(Deque* dq) {
    dq->rear--;
}

void popFront(Deque* dq) {
    dq->front++;
}

int front(Deque* dq) {
    return dq->data[dq->front];
}

int back(Deque* dq) {
    return dq->data[dq->rear - 1];
}

int solveQuery(int* arr, int n, int k) {
    Deque* dq = createDeque(n);
    int minOfMax = 1e9;

    for (int i = 0; i < n; i++) {
       
        if (!isEmpty(dq) && front(dq) <= i - k) {
            popFront(dq);
        }
        
        while (!isEmpty(dq) && arr[back(dq)] <= arr[i]) {
            popBack(dq);
        }
        pushBack(dq, i);

        
        if (i >= k - 1) {
            int windowMax = arr[front(dq)];
            if (windowMax < minOfMax) {
                minOfMax = windowMax;
            }
        }
    }
    free(dq->data);
    free(dq);
    return minOfMax;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        int ans = solveQuery(arr, n, k);
        printf("%d\n", ans);
    }
    return 0;
}
