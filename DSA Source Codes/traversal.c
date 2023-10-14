#include<stdio.h>
#include<stdlib.h>
// Traversal through an array
int main(){
    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < n; i++){
        int result = arr[i]*arr[i];
        printf("%d\t",result);
        result = 0;
    }
}
