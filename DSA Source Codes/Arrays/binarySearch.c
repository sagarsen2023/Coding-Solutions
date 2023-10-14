#include<stdio.h>
#include<stdlib.h>
// Binary search
int main(){
    int n,value,count = 0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: \n");
    for(int i = 0;i < n; i++){
        scanf("%d",&arr[i]);
    }
//     Sorting the array using the Bubble sort algorithm
        for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            if(arr[j] > arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
//     You can print the sorted array if you want to don so.
//     Implementing binary search
    printf("Enter the value you want to find: ");
    scanf("%d",&value);
    int low = 0, high = n, mid = (low+high/2);
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == value){
            printf("%d is available in the %d index position\n",value,mid);
            count++;
        }
        if (arr[mid] > value) high = mid - 1;
        else low = mid + 1;
    }
    if(count == 0) printf("The value isn't available");
    return 0;
}
