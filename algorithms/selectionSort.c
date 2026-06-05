#include <stdio.h>

void selectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void printArry(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

int main(){
    int array[] = {1, 10, 44, 76, 9};
    int arraySize = 5;

    printf("Before Sorting:\n");
    printArry(array, arraySize);

    selectionSort(array, arraySize);

    printf("After Sorting:\n");
    printArry(array, arraySize);

    return 0;
}

