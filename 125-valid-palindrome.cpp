#include <string>
#include <cctype> // for isalnum and tolower
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Check if the left character is alphanumeric
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            // Check if the right character is alphanumeric
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // Compare characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Example inputs
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    // Check if the strings are palindromes
    cout << "\"" << s1 << "\" is palindrome: " << (solution.isPalindrome(s1) ? "true" : "false") << std::endl;
    cout << "\"" << s2 << "\" is palindrome: " << (solution.isPalindrome(s2) ? "true" : "false") << std::endl;
    cout << "\"" << s3 << "\" is palindrome: " << (solution.isPalindrome(s3) ? "true" : "false") << std::endl;

    return 0;
}