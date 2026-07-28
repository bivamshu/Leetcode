#include <stdio.h>

typedef struct {
    int start;
    int finish;
} Activity;

void sortActivities(Activity a[], int n){
    int i, j;
    Activity temp;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j].finish > a[j+1].finish){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void activitySelection(Activity a[], int n){
    sortActivities(a, n);

    int i = 0;
    printf("(%d, %d)\n", a[j].start, a[j].finish);

    for(int j = 1; j < n; j++){
        if(a[j].start >= a[i].finish){
            printf("(%d, %d)\n", a[j].start, a[j].finish);
            i = j;
        }
    }
}

int main(){
    Activity activities[] = {
        {1, 2}, 
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9}, 
        {5, 9}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}