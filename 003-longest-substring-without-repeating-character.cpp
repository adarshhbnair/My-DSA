#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLen = 0; 
        unordered_set<char> charSet; // Set to store unique characters

        while (right < s.length()) {
            // If the character at right is already in the set
            if (charSet.count(s[right])) {
                // Remove the character at left from the set and move left pointer
                charSet.erase(s[left]);
                left++;
            } else {
                // Add the character at right to the set
                charSet.insert(s[right]);
                // Update maxLen if the current substring is longer
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }

        return maxLen; 
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " 
         << solution.lengthOfLongestSubstring(s) << endl; 
    return 0;
}