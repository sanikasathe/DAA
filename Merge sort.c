#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int* indices, int* result, int* temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int count = 0;
    while (i <= mid && j <= right) {
        if (nums[indices[i]] <= nums[indices[j]]) {
            result[indices[i]] += count;
            temp[k++] = indices[i++];
        } else {
            count++;
            temp[k++] = indices[j++];
        }
    }
    while (i <= mid) {
        result[indices[i]] += count;
        temp[k++] = indices[i++];
    }
    while (j <= right) {
        temp[k++] = indices[j++];
    }
    for (i = left; i <= right; i++) {
        indices[i] = temp[i];
    }
}

void mergeSort(int* nums, int* indices, int* result, int* temp, int left, int right) {
    int mid;
    if (left < right) {
        mid = left + (right - left) / 2;
        mergeSort(nums, indices, result, temp, left, mid);
        mergeSort(nums, indices, result, temp, mid + 1, right);
        merge(nums, indices, result, temp, left, mid, right);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int i;
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* indices = (int*)malloc(sizeof(int) * numsSize);
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        indices[i] = i;
        result[i] = 0;
    }
    mergeSort(nums, indices, result, temp, 0, numsSize - 1);
    free(indices);
    free(temp);
    return result;
}

void printArray(int arr[], int numsSize) {
    int i;
    printf("[");
    for (i = 0; i < numsSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("]");
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    printf("Original Array:");
    printf("[");
    int i;
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("]\n");
    int* counts = countSmaller(nums, numsSize, &returnSize);
    printf("Output: ");
    printArray(counts, numsSize);
    free(counts);
    return 0;
}
