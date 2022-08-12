#include <iostream>
#include <vector>

int maxProduct(const std::vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int mult = nums[0];
    int maxFirst = nums[0];
    int minFirst = nums[0];

    for (size_t i = 1; i < nums.size(); i++)
    {
        int mx = maxFirst * nums[i];
        int mn = minFirst * nums[i];

        maxFirst = std::max(mx, std::max(nums[i], mn));
        minFirst = std::min(mn, std::min(nums[i], mx));

        mult = std::max(maxFirst, mult);
    }

    return mult;
}

int main()
{
    /**
     * => 120
     */
    std::cout << maxProduct({ 0, -1, -2, 3, -4, 5 }) << std::endl;

    return 0;
}
