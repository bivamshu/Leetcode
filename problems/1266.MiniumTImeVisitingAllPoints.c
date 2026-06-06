#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int minTimeToVisitAllPoints(int** points, int pointsSize, int pointColSize){
    int totalTime = 0;

    for(int i = 0; i < pointsSize - 1; i++){
        int x1 = points[i][0];
        int y1 = points[i][1];

        int x2 = points[i + 1][0];
        int y2 = points[i + 1][1];

        int x_diff = abs(x2 - x1);
        int y_diff = abs(y2 - y1);

        if(x_diff > y_diff){
            totalTime += x_diff;
        } else{
            totalTime += y_diff;
        }
    }

    return totalTime;
}

int main(){
    int pointsSize = 3;
    int pointsColSize[] = {2, 2, 2};

    int** points = malloc(pointsSize * sizeof(int*));
    for(int i = 0; i < pointsSize - 1; i++){
        points[i] = malloc(2 * sizeof(int));
    }

    points[0][0] = 1; points[0][1] = 1;
    points[1][0] = 3; points[1][1] = 4;
    points[2][0] = -1; points[2][1] = 0;

    int* result = minTimeToVisitAllPoints(points, pointsSize, pointsColSize);
    printf("Minimum time to visit all points: %d seconds\n", result);

    for(int i = 0; i < pointsSize; i++){
        free(points[i]);
    }
    free(points);

    return 0;

}