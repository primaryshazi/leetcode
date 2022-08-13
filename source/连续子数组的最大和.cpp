#include <iostream>
#include <vector>

int maxSubArray(std::vector<int> &nums)
{
    int prevSum = 0;        // 记录到上个节点最大的子序列和
    int maxSum = nums[0];   // 记录最大子序列和

    for (auto i : nums)
    {
        prevSum = std::max(prevSum + i, i);
        maxSum = std::max(maxSum, prevSum);
    }

    return maxSum;
}

int main()
{
    std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    /**
     * = > 6
     */
    std::cout << maxSubArray(nums) << std::endl;

    return 0;
}
