#include<stdio.h>
#include<stdlib.h>
// linear search
int main(){
    int n,value,count = 0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: \n");
    for(int i = 0;i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value you want to find: ");
    scanf("%d",&value);
    for(int i = 0;i < n; i++){
        if(arr[i] == value){
            printf("The value is available at %d index position of the array\n",i);
            count++;
        }
    }   
    if(count == 0) printf("The value isn't available");
    return 0;
}