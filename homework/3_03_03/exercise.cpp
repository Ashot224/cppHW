#include <iostream>
#include <map>
#include <vector>

bool solve(const std::vector<int>& nums, int k)
{
    std::map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = mp.find(nums[i]);
        if (it != mp.end() && i - it->second <= k) {
            return true;
        }
        mp[nums[i]] = i;
    }

    return false;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    std::cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums<:i:>;
        if (i != nums.size() - 1)
            std::cout << ", ";
    }
    std::cout << "], k = " << k << "\n";

    bool result = solve(nums, k);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    nums = {1, 0, 1, 1};
    k = 1;
    std::cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums<:i:>;
        if (i != nums.size() - 1)
            std::cout << ", ";
    }
    std::cout << "], k = " << k << "\n";

    result = solve(nums, k);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    nums = {1, 2, 3, 1, 2, 3};
    k = 2;
    std::cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums<:i:>;
        if (i != nums.size() - 1)
            std::cout << ", ";
    }
    std::cout << "], k = " << k << "\n";

    result = solve(nums, k);
    std::cout << "Output: " << std::boolalpha << result << "\n";

    return 0;
}

