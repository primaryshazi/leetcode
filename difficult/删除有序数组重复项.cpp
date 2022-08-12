#include <iostream>
#include <vector>

size_t removeDuplicates(std::vector<int> &nums)
{
    size_t n = nums.size();

    if (n == 0)
    {
        return 0;
    }

    size_t fast = 1;
    size_t slow = 1;

    while (fast < n)
    {
        // 快指针指向不同的值，并将不同之值赋予慢指针
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }

    nums.erase(nums.begin() + slow, nums.end());

    return slow;
}

int main()
{
    std::vector<int> nums = { 1, 2, 2, 3, 3, 3, 4, 4, 5 };

    /**
     * => 5
     */
    std::cout << removeDuplicates(nums) << std::endl;

    return 0;
}
