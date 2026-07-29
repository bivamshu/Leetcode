#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASTER_SIZE 100000

int main(){
    FILE *fp = fopen("masterList.txt", "w");

    if(fp == NULL){
        printf("Error creating file.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));
    
    for(int i = 0; i < MASTER_SIZE; i++){
        int value = rand();
        fprintf(fp, "%d\n", value);
    }

    fclose(fp);

    printf("Master List generated successfully.\n");

    return 0;
}