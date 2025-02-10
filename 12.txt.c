#include <stdio.h>

void ma(int arr1[], int arr2[], int n, int result[]) {
    int i = 0, j = 0, k = 0;

    
    while (i < n && j < n) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < n) {
        result[k++] = arr1[i++];
    }

    while (j < n) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {0, 2, 4, 6, 8};
    int result[10];

    ma(arr1, arr2, 5, result);

    for (int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
