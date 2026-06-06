#include<stdio.h>

int insertionSort(int* array, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return* array;
}

void printArray(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
}

int main(){
    int array[] = {2, 8, 5, 3, 9, 4};
    int arraySize = 6;

    printf("Before Sorting:\n");
    printArray(array, arraySize);

    int result =insertionSort(array, arraySize);

    printf("After Sorting:\n");
    printArray(array, arraySize);

    return 0;

    
}