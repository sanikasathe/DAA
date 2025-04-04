#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array based on a fixed pivot index
int partition(int array[], int low, int high, int pivotIndex) {
    // Move the user-selected pivot element to the end temporarily
    swap(&array[pivotIndex], &array[high]);
    int pivot = array[high]; // The pivot element
    int i = low - 1;

    // Rearrange the elements around the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    // Place the pivot in its correct position
    swap(&array[i + 1], &array[high]);
    return i + 1; // Return pivot's final index
}

// Quick Sort function
void quickSort(int array[], int low, int high, int pivotIndex) {
    if (low < high) {
        // Partition the array using the fixed pivot index
        int pi = partition(array, low, high, pivotIndex);

        // Recursively sort elements before and after the partition
        quickSort(array, low, pi - 1, pivotIndex);
        quickSort(array, pi + 1, high, pivotIndex);
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n, pivotIndex;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Input the pivot index
    printf("Choose a pivot index between 0 and %d: ", n - 1);
    scanf("%d", &pivotIndex);

    // Validate the pivot index
    if (pivotIndex < 0 || pivotIndex >= n) {
        printf("Invalid pivot index! Please restart the program and choose a valid index.\n");
        return 1; // Exit the program
    }

    printf("Original array: ");
    printArray(array, n);

    // Sort the array using the user-defined pivot index
    quickSort(array, 0, n - 1, pivotIndex);

    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}
