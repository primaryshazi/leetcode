#include <iostream>
#include <vector>
#include <algorithm>

int longestConsecutive(std::vector<int> &nums)
{
    int len = static_cast<int>(nums.size());
    if (len < 2)
    {
        return len;
    }

    std::sort(nums.begin(), nums.end());

    int longest = 1;
    int cur = 1;
    for (int i = 1; i != len; ++i)
    {
        /**
         * 重复数字则予以跳过
         * 连续数字则加1
         * 非连续数字则重新计数
         */
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        if (nums[i] == nums[i - 1] + 1)
        {
            cur++;
        }
        else
        {
            longest = std::max(longest, cur);
            cur = 1;
        }
    }

    return std::max(longest, cur);
}


int main()
{
    std::vector<int> vi = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };

    /**
     * => 9
     */
    std::cout << longestConsecutive(vi) << std::endl;

    return 0;
}
