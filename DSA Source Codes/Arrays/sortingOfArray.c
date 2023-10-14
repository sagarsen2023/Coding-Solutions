// This program sorts an array of integers in ascending order.
// The user can choose between selection sort, bubble sort, or insertion sort.

#include <stdio.h>
#include <stdlib.h>

// Prints the contents of an array to the console.
void printArray(int size, int arr[]) {
  printf("The sorted array is: ");
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
}

// Sorts an array of integers using selection sort.
void selectionSort(int size, int arr[]) {
  // Iterate over the array, starting at the first element.
  for (int i = 0; i < size; i++) {
    // Find the smallest element in the remaining array.
    int minimum = arr[i];
    int index = i;
    for (int j = i + 1; j < size; j++) {
      if (minimum > arr[j]) {
        minimum = arr[j];
        index = j;
      }
    }

    // Swap the smallest element with the current element.
    int temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
  }
}

// Sorts an array of integers using bubble sort.
void bubbleSort(int size, int arr[]) {
  // Iterate over the array, starting at the first element.
  for (int i = 0; i < size; i++) {
    // Iterate over the remaining array, swapping adjacent elements if they are in the wrong order.
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// Sorts an array of integers using insertion sort.
void insertionSort(int size, int arr[]) {
  // Iterate over the array, starting at the second element.
  for (int i = 1; i < size; i++) {
    // Store the current element in a variable.
    int key = arr[i];

    // Iterate over the previous elements in the array, starting at the end.
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      // Shift the current element to the right.
      arr[j + 1] = arr[j];

      // Decrement the index of the previous element.
      j--;
    }

    // Insert the current element into the sorted array.
    arr[j + 1] = key;
  }
}

int main() {
  // Create an array of integers.
  int n, select = 1;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];

  // Get the elements of the array from the user.
  for (int i = 0; i < n; i++) {
    printf("Enter the element at index %d: ", i);
    scanf("%d", &arr[i]);
  }

  // Ask the user to choose a sorting algorithm.
  printf("\nEnter 1 for selection sort.\nEnter 2 for bubble sort.\nEnter 3 for insertion sort.\n");
  printf("Enter your selection: ");
  scanf("%d", &select);

  // Sort the array using the chosen algorithm.
  switch (select) {
    case 1:
      selectionSort(n, arr);
      break;
    case 2:
      bubbleSort(n, arr);
      break;
    case 3:
      insertionSort(n, arr);
      break;
    default:
      printf("You have entered an invalid selection.\n");
      break;
  }

  // Print the sorted array to the console.
  printArray(n, arr);

  return 0;
}
