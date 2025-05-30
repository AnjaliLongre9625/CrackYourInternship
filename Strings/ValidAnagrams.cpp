#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {// Check if the lengths of the two strings are different
            return false; 
        }

        unordered_map<char, int> mp; // Use char as key for characters

        for (auto c : s) {// Count occurrences of each character in the first string
            mp[c]++;
        }
        // Decrease the count for each character in the second string
        for (char c : t) {
            if (mp.find(c) == mp.end() || mp[c] == 0) {
                return false; // If the character is not found or count goes below 0, they are not anagrams
            }
            mp[c]--; // Decrement the count
        }

        return true; // If all counts are zero, they are anagrams
    }
};

int main() {
    Solution solution;

    // Test cases
    string str1, str2;

    // Input for first test case
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Check if the strings are anagrams
    if (solution.isAnagram(str1, str2)) {
        cout << str1 << " and " << str2 << " are anagrams." << endl;
    } else {
        cout << str1 << " and " << str2 << " are not anagrams." << endl;
    }

    return 0;
}
