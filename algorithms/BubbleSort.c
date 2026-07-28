#include <stdio.h> 

void bubbleSOrt(int arr[], int n){
    int i, j, temp; 

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}

//Time Complexity
/* 
Best Case: 0(n) (optimized version, already sorted)
Average Case: 0(n^2)
Worst Case: 0(n^2)

 */