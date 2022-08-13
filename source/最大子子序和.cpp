#include <iostream>
#include <vector>

int maxSubArray(const std::vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int thisSum = 0;
    int maxSum = nums[0];

    for (auto &i : nums)
    {
        thisSum += i;
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }
        if (thisSum < 0)
        {
            thisSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    std::vector<int> v1 = { 1, -2, 3, -4, 5, -6, 7 };
    std::vector<int> v2 = { 1, 2, -3, 4, 5, -6, 7 };
    std::vector<int> v3 = { -1, 2, 3, 4, 5, 6, -7 };

    /**
     * => 7
     * => 10
     * => 20
     */
    std::cout << maxSubArray(v1) << std::endl;
    std::cout << maxSubArray(v2) << std::endl;
    std::cout << maxSubArray(v3) << std::endl;

    return 0;
}