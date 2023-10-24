#include <stdio.h>

#define ROWS 8
#define COLS 8

void floodFill(int map[ROWS][COLS], int x, int y, int originalValue, int closedValue) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return; // Out of bounds
    }

    if (map[x][y] != originalValue) {
        return; // Cell already visited or not part of the area
    }

    // Change the value at the current point
    map[x][y] = closedValue;

    // Recur for the adjacent cells
    floodFill(map, x + 1, y, originalValue, closedValue);
    floodFill(map, x - 1, y, originalValue, closedValue);
    floodFill(map, x, y + 1, originalValue, closedValue);
    floodFill(map, x, y - 1, originalValue, closedValue);
}

// Utility function to print the map
void printMap(int map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the map is closed by 1s
int isMapClosed(int map[ROWS][COLS]) {
    // Find the first occurrence of 1 to start flood fill
    int startX = -1, startY = -1;
    for (int i = 0; i < ROWS && startX == -1; i++) {
        for (int j = 0; j < COLS && startY == -1; j++) {
            if (map[i][j] == 0) {
                startX = i;
                startY = j;
            }
        }
    }

    if (startX == -1 || startY == -1) {
        // No 1 found on the map
        return 0; // Map is not closed
    }

    // Use flood fill to mark the closed area with a different value
    int closedValue = 2;
    floodFill(map, startX, startY, 1, closedValue);

    // Check if there are any remaining 1s on the map
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 1) {
                return 0; // Map is not closed
            }
        }
    }

    return 1; // Map is closed
}

int main() {
    int map[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    printf("Original map:\n");
    printMap(map);

    if (isMapClosed(map)) {
        printf("\nThe map is closed by 1s.\n");
    } else {
        printf("\nThe map is not closed by 1s.\n");
    }

    return 0;
}