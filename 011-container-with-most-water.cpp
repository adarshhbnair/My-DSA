#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        
        while (left < right){
            int currentArea = min(height[left],height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Maximum area: " << solution.maxArea(height) << endl; // Output: 49
    return 0;
}