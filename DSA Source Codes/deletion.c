#include <stdio.h>
#include <stdlib.h>
// Deletion through an array
void deletion(int n, int arr[50]) {
    int deleteIndex, indexValue;
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\nEnter the position you want to delete ");
    scanf("%d", &deleteIndex);
    if (deleteIndex == n) {
        printf("Invalid position for deletion.\n");
    } else {
        n--;
        for (int i = deleteIndex; i < n; i++) {
            arr[i] = arr[i+1];
        }
        printf("Array after deletion: ");
        for (int i = 0; i < n; i++) {
            printf("%d  ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[50];
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    if (n > 50) {
        printf("Array size exceeds the maximum limit.\n");
        return 0;
    } else {
        deletion(n, arr);
    }
    return 0;
}