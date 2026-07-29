#include <stdio.h>
#include <stdlib.h>

#define MASTER_SIZE 100000

void createSample(const char *masterFile,
                  const char *outputFile,
                  int sampleSize)
{
    FILE *in = fopen(masterFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    int number;

    for (int i = 0; i < sampleSize; i++)
    {
        if (fscanf(in, "%d", &number) != 1)
            break;

        fprintf(out, "%d\n", number);
    }

    fclose(in);
    fclose(out);
}

int main()
{
    createSample("masterList.txt", "sample_1000.txt", 1000);
    createSample("masterList.txt", "sample_10000.txt", 10000);
    createSample("masterList.txt", "sample_20000.txt", 20000);
    createSample("masterList.txt", "sample_50000.txt", 50000);
    createSample("masterList.txt", "sample_100000.txt", 100000);

    printf("Nested samples created successfully.\n");

    return 0;
}