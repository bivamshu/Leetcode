#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* nums, int low, int high){
    int random_index = low + rand() % (high - low + 1);
    swap(&nums[random_index], &nums[high]);

    int pivot = nums[high];
    int i = (low - 1); //Index of the smaller element

    for(int j = low; j < high; j++){
        //If current element is smaller than orequal to the pivot
        if(nums[j] <= pivot){
            i++;
            swap(&nums[i], &nums[j]);
        }
    }    //Place the pivot in its correc position
    swap(&nums[i+1], &nums[high]);
    return(i + 1);
}


void quickSort(int* nums, int low, int high){
    if(low<high){
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high); 
    }
}

bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize <= 1) return false;

    quickSort(nums, 0, numsSize - 1); 

    for(int i =0; i<numsSize - 1; i++){
        if(nums[i] == nums[i + 1]){
            return true;
        }
    }

    return false;
}

int main(){
    int nums = [1, 1, 2, 3, 5];
    int arraySize = 5;
    containsDuplicate(nums, arraySize);
    return 0;
}