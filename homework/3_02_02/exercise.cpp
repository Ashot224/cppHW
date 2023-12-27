
#include <iostream>
#include <map>
#include <vector>

int solve(const std::string& str, std::string& palindrome)
{
    std::map<char, int> mp;

    for (char ch : str) {
        ++mp[ch];
    }

    std::vector<char> PalindromeLetters;
    int result = 0;
    char middleOne = 0;
    bool middleTaken = false;

    for (std::pair<char, int> p : mp) {
        if (!middleTaken && p.second % 2) {
            middleOne = p.first;
            middleTaken = true;
        }

        int count = p.second / 2;
        result += count;

        for (int i = 0; i < count; ++i) {
            PalindromeLetters.push_back(p.first);
        }
            
    }

    result *= 2;

    if (middleOne) {
        PalindromeLetters.push_back(middleOne);
        ++result;
    }
    std::string tmp(PalindromeLetters.begin(), PalindromeLetters.end());
    palindrome = tmp;

    int saveSize = static_cast<int>(palindrome.size() - 1);
    for (int i = saveSize - 1; i >= 0; --i) {
        palindrome += palindrome[i];
    }
    return result;
}


int main()
{
    std::string str, palindrome;

    str = "acbcccdd";
    std::cout << "Input: str = \"" << str << "\"\n";

    int result = solve(str, palindrome);
    std::cout << "Output: " << result << "\n";
    std::cout << "Explanation: One longest palindrome that can be built is \"" 
              << palindrome << "\", with the length of " << result << ".\n";

    return 0;
}

