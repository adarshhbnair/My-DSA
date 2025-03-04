#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // Count of each character (A-Z)
        int left = 0, right = 0; // Pointers for the sliding window
        int maxCount = 0; // Maximum count of a single character in the current window
        int maxLength = 0; // Maximum length of valid substring found

        // Expand the window with the right pointer
        while (right < s.length()) {
            count[s[right] - 'A']++; // Increment the count of the current character
            maxCount = max(maxCount, count[s[right] - 'A']); // Update maxCount

            // Check if the current window is valid
            if ((right - left + 1) - maxCount > k) {
                // If not valid, shrink the window from the left
                count[s[left] - 'A']--; // Decrement the count of the character at the left pointer
                left++; // Move the left pointer to the right
            }

            // Update the maximum length of valid substring found
            maxLength = max(maxLength, right - left + 1);
            right++; // Move the right pointer to the right
        }

        return maxLength; // Return the maximum length found
    }
};

int main() {
    Solution solution;
    string s = "AABABBA"; // Example input
    int k = 1; // Number of characters we can replace
    cout << "Length of longest substring: " << solution.characterReplacement(s, k) << endl; // Output the result
    return 0;
}