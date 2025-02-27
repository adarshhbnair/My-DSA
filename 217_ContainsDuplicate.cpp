#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true; // Duplicate found
            }
            seen.insert(num);
        }

        return false; // No duplicates found
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5, 1};
    if (solution.containsDuplicate(nums)) {
        std::cout << "Duplicates found!" << std::endl;
    } else {
        std::cout << "No duplicates." << std::endl;
    }
    return 0;
}