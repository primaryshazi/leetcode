#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int> &nums)
{
    std::unordered_set<int> unorder;
    for (auto i : nums)
    {
        if (unorder.find(i) != unorder.end())
        {
            return true;
        }
        unorder.emplace(i);
    }

    return false;
}

int main()
{
    std::vector<int> nums1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1 };
    std::vector<int> nums2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

    /**
     * => 1
     * => 0
     */
    std::cout << containsDuplicate(nums1) << std::endl;
    std::cout << containsDuplicate(nums2) << std::endl;

    return 0;
}
