#include <iostream>
#include <map>
#include <sstream>


bool solve(const std::string& pattern, const std::string& s)
{
    std::map<std::string, char> mp;
    std::stringstream ss(s);
    std::string word;

    char c = 'a';
    std::string result{};
    while (ss >> word) {
        auto it = mp.find(word);
        if (it != mp.end()) {
            result += it->second;
        } else {
            mp.insert(std::make_pair(word, c));
            result += c;
            c++;
        }
    }

    return result == pattern;
}

int main()
{
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";
    std::cout << "Input: pattern = \"" << pattern << "\", s = \"" << s << "\"\n";

    bool result = solve(pattern, s);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    pattern = "abba";
    s = "dog cat cat fish";
    std::cout << "Input: pattern = \"" << pattern << "\", s = \"" << s << "\"\n";

    result = solve(pattern, s);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    pattern = "aaaa";
    s = "dog cat cat dog";
    std::cout << "Input: pattern = \"" << pattern << "\", s = \"" << s << "\"\n";

    result = solve(pattern, s);
    std::cout << "Output: " << std::boolalpha << result << "\n";

    return 0;
}

