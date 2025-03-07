#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0; // Start pointer at the beginning of the array
        int right = nums.size() - 1; // End pointer at the end of the array

        // Loop until the left pointer exceeds the right pointer
        while (left <= right) {
            int middle = left + (right - left) / 2; // Calculate the middle index

            // Check if the middle element is the target
            if (nums[middle] == target) {
                return middle; // Target found, return the index
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[middle]) {
                // Check if the target is in the sorted left half
                if (target >= nums[left] && target < nums[middle]) {
                    right = middle - 1; // Move to the left half
                } else {
                    left = middle + 1; // Move to the right half
                }
            } else { // The right half must be sorted
                // Check if the target is in the sorted right half
                if (target > nums[middle] && target <= nums[right]) {
                    left = middle + 1; // Move to the right half
                } else {
                    right = middle - 1; // Move to the left half
                }
            }
        }

        return -1; // Target not found, return -1
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array
    int target = 0; // Example target to search for

    int result = solution.search(nums, target); // Perform the search
    if (result != -1) {
        cout << "Target " << target << " found at index: " << result << endl; // Output the result
    } else {
        cout << "Target " << target << " not found in the array." << endl; // Output if not found
    }

    return 0; // Indicate successful completion
}