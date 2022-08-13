#include <iostream>
#include <vector>

int findRepeatNumber(std::vector<int> &nums)
{
    // 由于索引范围与元素范围一致，故将每个元素移动到与其值相同的索引位置
    for (int i = 0; i < static_cast<int>(nums.size()); i++)
    {
        while (i != nums[i])
        {
            // 当前元素与索引不等，而元素值索引位置的数据与当前值相等则重复
            if (nums[i] == nums[nums[i]])
            {
                return nums[i];
            }
            std::swap(nums[i], nums[nums[i]]);
        }
    }

    return -1;
}

int main()
{
    std::vector<int> v1 = { 1, 3, 5, 4, 3, 2, 6, 7 };
    std::vector<int> v2 = { 1, 3, 5, 4, 0, 2, 6, 7 };

    /**
     * => 3
     * => -1
     */
    std::cout << findRepeatNumber(v1) << std::endl;
    std::cout << findRepeatNumber(v2) << std::endl;

    return 0;
}
