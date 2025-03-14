#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size()-1, leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }

        return water; 
    }
};

int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped water: " << solution.trap(height) << endl;
    return 0;
}