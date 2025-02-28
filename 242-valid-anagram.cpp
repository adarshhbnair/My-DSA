#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};

        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (char ch : t) {
            count[ch - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Is \"" << s1 << "\" an anagram of \"" << t1 << "\"? " 
              << (solution.isAnagram(s1, t1) ? "Yes" : "No") << std::endl;

    string s2 = "rat";
    string t2 = "car";
    cout << "Is \"" << s2 << "\" an anagram of \"" << t2 << "\"? " 
              << (solution.isAnagram(s2, t2) ? "Yes" : "No") << std::endl;

    string s3 = "listen";
    string t3 = "silent";
    cout << "Is \"" << s3 << "\" an anagram of \"" << t3 << "\"? " 
              << (solution.isAnagram(s3, t3) ? "Yes" : "No") << std::endl;

    string s4 = "hello";
    string t4 = "world";
    cout << "Is \"" << s4 << "\" an anagram of \"" << t4 << "\"? " 
              << (solution.isAnagram(s4, t4) ? "Yes" : "No") << std::endl;

    return 0;
}