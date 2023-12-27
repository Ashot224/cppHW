#include <iostream>
#include <unordered_set>

int 
countJewelsInStones(const std::string& jewels, const std::string& stones) 
{
    std::unordered_set<char> jewelSet(jewels.begin(), jewels.end());

    int count = 0;
    for (char stone : stones) {
        if (jewelSet.count(stone) > 0) {
            count++;
        }
    }

    return count;
}

int main() {
    std::string jewels, stones;

    std::cout << "Input jewels: ";
    std::cin >> jewels;

    std::cout << "input stones: ";
    std::cin >> stones;

    std::cout << countJewelsInStones(jewels, stones) << std::endl;

    return 0;
}

