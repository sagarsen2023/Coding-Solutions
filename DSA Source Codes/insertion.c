#include <stdio.h>
#include <stdlib.h>
// insertion through an array
void insertion(int n, int arr[50]){
    int insertIndex, indexValue;
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
    printf("\nEnter in which position you want to add a new value: ");
    scanf("%d", &insertIndex);
    if(indexValue == 50){
        printf("Sorry some error occured.");
    } else {
        printf("Enter the value: ");
        scanf("%d", &indexValue);
        n++;
        for(int i = n; i > insertIndex; i--){
            arr[i] = arr[i-1];
        }
        arr[insertIndex] = indexValue;
        for (int i = 0; i < n; i++){
            printf("%d  ", arr[i]);
        }
    }
    
}
int main()
{
    int arr[50];
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    if (n>50) {
        printf("Please try again.\n");
        exit(0);
    }else{
        insertion(n,arr);
    }
}