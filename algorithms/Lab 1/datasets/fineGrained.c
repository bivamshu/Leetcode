#include <stdio.h>
#include <stdlib.h>

#define MASTER_SIZE 100000

int master[MASTER_SIZE];

// Read master list into memory
void loadMaster(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cannot open master file.\n");
        exit(1);
    }

    for (int i = 0; i < MASTER_SIZE; i++)
        fscanf(fp, "%d", &master[i]);

    fclose(fp);
}

// Create one fine-grained sample
void createFineSample(const char *filename, int start, int size)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Cannot create file.\n");
        exit(1);
    }

    for (int i = start; i < start + size; i++)
        fprintf(fp, "%d\n", master[i]);

    fclose(fp);
}

int main()
{
    loadMaster("masterList.txt");

    int start = 0;

    for (int size = 1000; size <= 10000; size += 1000)
    {
        char filename[30];

        sprintf(filename, "fine_%d.txt", size);

        createFineSample(filename, start, size);

        start += size;
    }

    printf("Fine-grained datasets created successfully.\n");

    return 0;
}