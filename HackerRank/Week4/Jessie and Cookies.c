#include <stdio.h>
#include <stdlib.h>

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heap functions
void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) 
        smallest = left;
    if (right < size && heap[right] < heap[smallest]) 
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] < heap[parent]) {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

int extractMin(int heap[], int *size) {
    if (*size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, (*size) - 1);
}

// Main function
int cookies(int k, int arr[], int n) {
    // Build min-heap
    for (int i = (n - 2) / 2; i >= 0; i--)
        heapifyDown(arr, n, i);

    int operations = 0;
    while (n > 0 && arr[0] < k) {
        if (n < 2) return -1; // Not enough cookies to mix

        int least = extractMin(arr, &n);
        int secondLeast = extractMin(arr, &n);

        int newSweetness = least + 2 * secondLeast;
        insertHeap(arr, &n, newSweetness);
        operations++;
    }
    return operations;
}

// Driver
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = cookies(k, arr, n);
    printf("%d\n", result);
    return 0;
}
