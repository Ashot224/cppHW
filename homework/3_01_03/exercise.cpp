#include <iostream>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(const std::string& s) {
    int left = 0;
    int right = s.size();

    while (left < right) {
        int mid = (left + right) / 2;
        bool found = false;

        for (int i = 0; i <= s.size() - mid; ++i) {
            std::unordered_set<char> uniqueChars(s.begin() + i, s.begin() + i + mid);
            if (uniqueChars.size() == mid) {
                found = true;
                break;
            }
        }

        if (found) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left - 1;
}

int main() {
    std::string s1 = "abcabcbb";
    std::string s2 = "bbbbb";
    std::string s3 = "pwwkew";

    std::cout << "Input: " << s1 << " Output: " << lengthOfLongestSubstring(s1) << std::endl;
    std::cout << "Input: " << s2 << " Output: " << lengthOfLongestSubstring(s2) << std::endl;
    std::cout << "Input: " << s3 << " Output: " << lengthOfLongestSubstring(s3) << std::endl;

    return 0;
}

