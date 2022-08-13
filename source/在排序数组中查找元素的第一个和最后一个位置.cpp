#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> searchRange(const std::vector<int> &nums, int target)
{
    // 找到第一个大于等于target的值的索引
    int left = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    // 找到第一个大于target的值的索引
    int right = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (left <= right && left >= 0 && right < static_cast<int>(nums.size()) && nums[left] == target && nums[right] == target)
    {
        return { left, right };
    }
    return { -1, -1 };
}

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5 };
    std::vector<int> v2 = { 1, 2, 3, 3, 4, 5 };
    std::vector<int> v3 = { 3, 3, 3, 3, 3 };

    auto r1 = searchRange(v1, 3);
    auto r2 = searchRange(v2, 3);
    auto r3 = searchRange(v3, 3);
    auto r4 = searchRange(v3, 0);

    /**
     * => 2  2
     * => 2  3
     * => 0  4
     * => -1  -1
     */
    std::cout << r1[0] << "  " << r1[1] << std::endl;
    std::cout << r2[0] << "  " << r2[1] << std::endl;
    std::cout << r3[0] << "  " << r3[1] << std::endl;
    std::cout << r4[0] << "  " << r4[1] << std::endl;

    return 0;
}
