#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

struct Activity {
    int start;
    int finish;
};

void sortActivities(struct Activity a[], int n) {
    struct Activity temp;

    // Bubble sort for demonstration
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j].finish > a[j+1].finish) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


void activitySelection(struct Activity a[], int n) {

    sortActivities(a, n);

    int lastFinish = a[0].finish;

    for(int i = 1; i < n; i++) {

        if(a[i].start >= lastFinish)
            lastFinish = a[i].finish;
    }
}


int main() {

    FILE *fp = fopen("complexity.dat", "w");

    srand(time(NULL));

    for(int n = 100; n <= 1000; n += 100) {

        struct Activity a[n];

        for(int i=0;i<n;i++) {
            a[i].start = rand()%1000;
            a[i].finish = a[i].start + rand()%100;
        }


        clock_t start = clock();

        activitySelection(a,n);

        clock_t end = clock();


        double time_taken =
        ((double)(end-start))/CLOCKS_PER_SEC;


        fprintf(fp,"%d %lf\n", n, time_taken);

        printf("%d %.6lf\n", n, time_taken);
    }


    fclose(fp);

    return 0;
}