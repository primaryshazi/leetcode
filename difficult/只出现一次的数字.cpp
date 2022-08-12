#include <iostream>
#include <vector>

int singleNumber(const std::vector<int> &nums)
{
    size_t length = nums.size();
    if (length == 0)
    {
        return 0;
    }

    int result = nums[0];
    for (int i = 1; i < length; i++)
    {
        result ^= nums[i];
    }

    return result;
}

int main()
{
    /**
     * => 4
     */
    std::cout << singleNumber({1, 2, 3, 4, 3, 2, 1}) << std::endl;

    return 0;
}
