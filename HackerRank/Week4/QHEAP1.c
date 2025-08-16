#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int size = 0;

// Swap helper
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify Up (for insertion)
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify Down (for deletion)
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert element
void insert(int val) {
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
}

// Find index of element
int findIndex(int val) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == val)
            return i;
    }
    return -1; // should not happen due to constraints
}

// Delete element
void deleteVal(int val) {
    int index = findIndex(val);
    if (index == -1) return;

    heap[index] = heap[size - 1];
    size--;

    heapifyUp(index);
    heapifyDown(index);
}

// Get minimum element
int getMin() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {          // Insert
            scanf("%d", &x);
            insert(x);
        } 
        else if (type == 2) {     // Delete
            scanf("%d", &x);
            deleteVal(x);
        } 
        else if (type == 3) {     // Print Min
            printf("%d\n", getMin());
        }
    }
    return 0;
}
