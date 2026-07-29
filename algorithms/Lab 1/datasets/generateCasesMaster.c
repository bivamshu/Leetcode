#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void copyArray(int a[], int b[], int n)
{
    for(int i=0;i<n;i++)
        b[i]=a[i];
}


void reverse(int arr[], int n)
{
    int temp;

    for(int i=0;i<n/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}


// Simple bubble sort for creating cases
void sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


void generateCases(char *inputFile, 
                   char *name,
                   int n)
{
    int *original = malloc(n*sizeof(int));
    int *best = malloc(n*sizeof(int));
    int *worst = malloc(n*sizeof(int));


    FILE *fp=fopen(inputFile,"r");


    if(fp==NULL)
    {
        printf("Cannot open %s\n",inputFile);
        return;
    }


    for(int i=0;i<n;i++)
        fscanf(fp,"%d",&original[i]);

    fclose(fp);



    // BEST CASE
    copyArray(original,best,n);

    sort(best,n);


    // WORST CASE
    copyArray(best,worst,n);

    reverse(worst,n);



    char filename[200];


    // Save best
    sprintf(filename,"datasets/Master/best/%s.txt",name);

    fp=fopen(filename,"w");

    for(int i=0;i<n;i++)
        fprintf(fp,"%d\n",best[i]);

    fclose(fp);



    // Save worst
    sprintf(filename,"Master/worst/%s.txt",name);

    fp=fopen(filename,"w");

    for(int i=0;i<n;i++)
        fprintf(fp,"%d\n",worst[i]);

    fclose(fp);



    // Save average(original random)
    sprintf(filename,"Master/average/%s.txt",name);

    fp=fopen(filename,"w");

    for(int i=0;i<n;i++)
        fprintf(fp,"%d\n",original[i]);

    fclose(fp);



    free(original);
    free(best);
    free(worst);
}



int main()
{

    generateCases(
        "Master/sample_1000.txt",
        "sample_1000",
        1000
    );


    generateCases(
        "Master/sample_10000.txt",
        "sample_10000",
        10000
    );


    generateCases(
        "Master/sample_20000.txt",
        "sample_20000",
        20000
    );


    generateCases(
        "Master/sample_50000.txt",
        "sample_50000",
        50000
    );


    generateCases(
        "Master/sample_100000.txt",
        "sample_100000",
        100000
    );


    printf("Cases generated successfully\n");

    return 0;
}