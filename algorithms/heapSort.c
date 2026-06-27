#include<stdio.h>

//Function to swap two elements. 

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[])