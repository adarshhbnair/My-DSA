#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int m = matrix.size(); // Number of rows
        if (m == 0) return false; // If the matrix is empty
        int n = matrix[0].size(); // Number of columns
        int topRow = 0; // Start pointer for rows
        int bottomRow = m - 1; // End pointer for rows
        int leftCol = 0; // Start pointer for columns
        int rightCol = n - 1; // End pointer for columns

        // Binary search on rows
        while (topRow <= bottomRow) {
            int midRow = topRow + (bottomRow - topRow) / 2;

            // Check if the target is within the range of the current row
            if (matrix[midRow][0] <= target && target <= matrix[midRow][n - 1]) {
                // Perform binary search on the found row
                while (leftCol <= rightCol) {
                    int midCol = leftCol + (rightCol - leftCol) / 2;

                    if (matrix[midRow][midCol] == target) {
                        return true; // Target found
                    } else if (matrix[midRow][midCol] < target) {
                        leftCol = midCol + 1; // Move to the right half
                    } else {
                        rightCol = midCol - 1; // Move to the left half
                    }
                }
                break; // Exit the row search loop
            } else if (matrix[midRow][0] > target) {
                bottomRow = midRow - 1; // Move to the upper half
            } else {
                topRow = midRow + 1; // Move to the lower half
            }
        }

        return false; // Target not found
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
        {60, 70, 80, 90}
    }; // Example matrix
    int target = 16; // Example target
    bool result = solution.searchMatrix(matrix, target); // Perform the search
    cout << "Target " << target << (result ? " found." : " not found.") << endl; // Output the result
    return 0;
}