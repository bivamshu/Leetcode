#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ROW 9
#define COL 10

// Structure to represent a cell/node in the grid
typedef struct {
    int x, y;          // Coordinates
    int parent_x, parent_y; // To reconstruct the final path
    double f, g, h;    // f = g + h
} Node;

// Check if a cell is valid (inside grid boundaries)
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Check if a cell is an unblocked open path
bool isUnblocked(int grid[ROW][COL], int row, int col) {
    return (grid[row][col] == 0);
}

// Check if destination cell has been reached
bool isDestination(int row, int col, int dest_x, int dest_y) {
    return (row == dest_x && col == dest_y);
}

// Calculate the Euclidean Distance heuristic h(n)
double calculateHValue(int row, int col, int dest_x, int dest_y) {
    return sqrt((row - dest_x) * (row - dest_x) + (col - dest_y) * (col - dest_y));
}

// Reconstruct and print the path from destination to source
void tracePath(Node cellDetails[ROW][COL], int dest_x, int dest_y) {
    printf("\nThe Path is: ");
    int row = dest_x;
    int col = dest_y;

    // We can use a small stack layout or print coordinates backwards
    while (!(cellDetails[row][col].parent_x == row && cellDetails[row][col].parent_y == col)) {
        printf("-> (%d,%d) ", row, col);
        int temp_row = cellDetails[row][col].parent_x;
        int temp_col = cellDetails[row][col].parent_y;
        row = temp_row;
        col = temp_col;
    }
    printf("-> (%d,%d)\n", row, col);
}

// The A* Search Algorithm
void aStarSearch(int grid[ROW][COL], int src_x, int src_y, int dest_x, int dest_y) {
    if (!isValid(src_x, src_y) || !isValid(dest_x, dest_y)) {
        printf("Source or destination is invalid\n");
        return;
    }

    if (!isUnblocked(grid, src_x, src_y) || !isUnblocked(grid, dest_x, dest_y)) {
        printf("Source or the destination is blocked\n");
        return;
    }

    if (isDestination(src_x, src_y, dest_x, dest_y)) {
        printf("We are already at the destination\n");
        return;
    }

    // Closed list tracking: closedStatus[i][j] = true if node is evaluated
    bool closedList[ROW][COL] = {false};

    // Hold details of the 2D map tracks
    Node cellDetails[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cellDetails[i][j].f = INFINITY;
            cellDetails[i][j].g = INFINITY;
            cellDetails[i][j].h = INFINITY;
            cellDetails[i][j].parent_x = -1;
            cellDetails[i][j].parent_y = -1;
        }
    }

    // Initialize parameters of the starting node
    int i = src_x, j = src_y;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_x = i;
    cellDetails[i][j].parent_y = j;

    // Simplified Open List tracking array
    // Store active tracking configurations dynamically
    Node openList[ROW * COL];
    int openListCount = 0;

    // Put the starting node on the open list
    openList[openListCount] = cellDetails[i][j];
    openList[openListCount].x = i;
    openList[openListCount].y = j;
    openListCount++;

    bool foundDest = false;

    while (openListCount > 0) {
        // Find the node with the least 'f' value in the open list
        int minIdx = 0;
        for (int k = 1; k < openListCount; k++) {
            if (openList[k].f < openList[minIdx].f) {
                minIdx = k;
            }
        }

        // Pop the node from the open list
        Node curr = openList[minIdx];
        for (int k = minIdx; k < openListCount - 1; k++) {
            openList[k] = openList[k + 1];
        }
        openListCount--;

        i = curr.x;
        j = curr.y;
        closedList[i][j] = true;

        // Direction arrays to check 8 possible movements (Up, Down, Left, Right, Diagonals)
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

        for (int d = 0; d < 8; d++) {
            int newX = i + dx[d];
            int newY = j + dy[d];

            if (isValid(newX, newY)) {
                if (isDestination(newX, newY, dest_x, dest_y)) {
                    cellDetails[newX][newY].parent_x = i;
                    cellDetails[newX][newY].parent_y = j;
                    printf("The destination cell is found\n");
                    tracePath(cellDetails, dest_x, dest_y);
                    foundDest = true;
                    return;
                }
                else if (!closedList[newX][newY] && isUnblocked(grid, newX, newY)) {
                    // Cost for diagonal movement is sqrt(2) (~1.414), horizontal/vertical is 1.0
                    double moveCost = (dx[d] != 0 && dy[d] != 0) ? 1.414 : 1.0;
                    double gNew = cellDetails[i][j].g + moveCost;
                    double hNew = calculateHValue(newX, newY, dest_x, dest_y);
                    double fNew = gNew + hNew;

                    // If it isn't on the open list or if found path is cheaper
                    if (cellDetails[newX][newY].f == INFINITY || cellDetails[newX][newY].f > fNew) {
                        openList[openListCount].x = newX;
                        openList[openListCount].y = newY;
                        openList[openListCount].f = fNew;
                        openListCount++;

                        // Update details of this cell
                        cellDetails[newX][newY].f = fNew;
                        cellDetails[newX][newY].g = gNew;
                        cellDetails[newX][newY].h = hNew;
                        cellDetails[newX][newY].parent_x = i;
                        cellDetails[newX][newY].parent_y = j;
                    }
                }
            }
        }
    }

    if (!foundDest) printf("Failed to find the Destination Cell\n");
}

int main() {
    // 0: Open path, 1: Obstacle/Wall
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    // Source coordinates
    int src_x = 8, src_y = 0;
    // Destination coordinates
    int dest_x = 0, dest_y = 0;

    aStarSearch(grid, src_x, src_y, dest_x, dest_y);

    return 0;
}