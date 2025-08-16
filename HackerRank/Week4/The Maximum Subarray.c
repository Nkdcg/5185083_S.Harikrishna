#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void maxSubarray(int arr[], int n) {
    int max_subarray = arr[0];  
    int current_sum = arr[0];

    int max_subsequence = arr[0]; 
    if (arr[0] > 0) 
        max_subsequence = arr[0];

    for (int i = 1; i < n; i++) {
        
        current_sum = max(arr[i], current_sum + arr[i]);
        max_subarray = max(max_subarray, current_sum);

        if (arr[i] > 0) {
            if (max_subsequence < 0)  
                max_subsequence = arr[i];
            else
                max_subsequence += arr[i];
        } else {
            max_subsequence = max(max_subsequence, arr[i]);
        }
    }

    printf("%d %d\n", max_subarray, max_subsequence);
}

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        maxSubarray(arr, n);
    }
    return 0;
}
