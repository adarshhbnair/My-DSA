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
            // Calculate the middle index
            int mid = left + (right - left) / 2;

            // Check if the middle element is the target
            if (nums[mid] == target) {
                return mid; // Target found, return the index
            } else if (nums[mid] > target) {
                // Target is in the left half
                right = mid - 1; // Move the right pointer to mid - 1
            } else {
                // Target is in the right half
                left = mid + 1; // Move the left pointer to mid + 1
            }
        }

        return -1; // Target not found, return -1
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Example sorted array
    int target = 5; // Example target
    int result = solution.search(nums, target); // Perform the search
    cout << "Index of target " << target << ": " << result << endl; // Output the result
    return 0;
}