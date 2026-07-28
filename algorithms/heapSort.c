#include <stdio.h>

//Function to heapify a subtree rooted at index i

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int i, temp;

    for(i = n / 2 - 1; i > 0; i--){
        heapify(arr, n, i);
    }

    for(i = n - 1; i > 0; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}