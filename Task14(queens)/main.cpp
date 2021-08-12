#include <iostream>

using namespace std;

// Function for counting the number of possible placements.
void placementOfQueens(int N, int &counter, int *queensPositions, int currentColumn) {
    bool thisPositionIsAcceptable;

    if (currentColumn >= N) { // If all queens are placed, then we increase the counter and exit the function.
        counter++;
    } else {
        for (int i = 0; i < N; i++) { // In the current column, step by step move the queen down from the zero row.
            queensPositions[currentColumn] = i;
            thisPositionIsAcceptable = 1;

            for (int j = 0; j < currentColumn; j++) {
                if ((queensPositions[j] == queensPositions[currentColumn]) ||
                    (queensPositions[j] + j == queensPositions[currentColumn] + currentColumn) ||
                    (queensPositions[j] - j == queensPositions[currentColumn] - currentColumn)) {
                    thisPositionIsAcceptable = 0;
                }
            }
            if (thisPositionIsAcceptable) placementOfQueens(N, counter, queensPositions, currentColumn + 1);
            /* If in this position the queen does not beat any other queen to the left of itself,
             * then recursively run the function that moves the next queen in the next column. */
        }
        queensPositions[currentColumn] = -1; // We return the queen in the current column to its original position.
    }
}

int main() {
    int N;
    int counter = 0; // Counter of suitable placement of queens.

    cin >> N;
    int *queensPositions = new int[N];
    for (int i = 0; i < N; i++) {
        queensPositions[i] = -1; // For convenience, all queens are initially in the non-existent -1 row.
    } // Create a field in which the given element of the array is the coordinate of the queen in the given column.

    placementOfQueens(N, counter, queensPositions, 0);
    cout << counter;

    delete[] queensPositions;
    return 0;
}
