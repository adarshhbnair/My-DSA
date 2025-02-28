#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : numSet) {
            // Check if the current number is the start of a consecutive sequence
            if (numSet.count(num - 1) == 0) {
                int length = 1;

                // Iterate through consecutive numbers starting from the current number
                while (numSet.count(num + length) != 0) {
                    length++;
                }

                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {100, 4, 200, 1, 3, 2, 5, 7};

    // Find the length of the longest consecutive sequence
    int result = solution.longestConsecutive(nums);
    cout << "The length of the longest consecutive sequence is: " << result << endl;

    return 0;
}