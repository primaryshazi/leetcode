#include <iostream>
#include <vector>

size_t removeElement(std::vector<int> &nums, int val)
{
    size_t n = nums.size();

    if (n == 0)
    {
        return 0;
    }

    size_t fast = 0;
    size_t slow = 0;

    while (fast < n)
    {
        // 快指针指向不同的值，并将不同之值赋予慢指针
        if (nums[fast] != val)
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
    std::vector<int> nums = { 1, 2, 2, 3, 3, 3, 4, 4, 5, 4, 3, 2, 1 };

    /**
     * => 9
     */
    std::cout << removeElement(nums, 3) << std::endl;

    return 0;
}
