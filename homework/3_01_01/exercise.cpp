#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<int> uniqueValues;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;  
        uniqueValues.insert(value);
    }

    std::cout << uniqueValues.size() << std::endl;

    return 0;
}

