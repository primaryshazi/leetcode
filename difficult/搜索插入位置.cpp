#include <iostream>
#include <vector>

int searchInsert(const std::vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int ans = n;

    while (left <= right)
    {
        int mid = (right + left) >> 1;

        if (target <= nums[mid])
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    std::vector<int> nums = { 1, 2, 3, 4, 5 };

    /**
     * => 2
     * => 4
     * => 5
     */
    std::cout << searchInsert(nums, 3) << std::endl;
    std::cout << searchInsert(nums, 5) << std::endl;
    std::cout << searchInsert(nums, 6) << std::endl;

    return 0;
}
