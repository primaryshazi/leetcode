#include <iostream>
#include <vector>

int rob(const std::vector<int> &nums)
{
    size_t size = nums.size();

    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return nums[0];
    }

    int first = nums[0];    // 记录第k - 2总金额
    int second = std::max(nums[0], nums[1]); // 记录第k - 1总金额

    /**
     * 若偷当前房屋则总金额为nums[k] + nums[k - 2]
     * 若不偷当前房屋则总金额为nums[k - 1]
     * 二者取较大者即为最大金额
     */
    for (size_t i = 2; i < size; i++)
    {
        int temp = second;
        second = std::max(first + nums[i], second);
        first = temp;
    }

    return second;
}

int main()
{
    /**
     * => 25
     */
    std::cout << rob({ 1, 2, 3, 4, 5, 6, 7, 8 ,9 }) << std::endl;

    return 0;
}
