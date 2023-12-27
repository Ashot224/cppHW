#include <iostream>
#include <map>

int main()
{
    std::map<char, int> mp;
    std::string str = "apple";
    for (char ch : str) {
        ++mp[ch];
    }

    for (int i = 0; i < str.length(); ++i) {
        auto it = mp.find(str[i]);
        if (it->second == 1) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}

