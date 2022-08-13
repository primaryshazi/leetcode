#include <iostream>
#include <vector>

int search(std::vector<int> &nums, int target)
{
    int index = -1;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (target > nums[mid])
        {
            left = mid + 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            index = mid;
            break;
        }
    }

    return index;
}

int main()
{
    std::vector<int> nums = { 0, 1, 3, 5, 7, 9, 10 };

    /**
     * => 0  0
     * => 1  1
     * => 2  -1
     * => 3  2
     * => 4  -1
     * => 5  3
     * => 6  -1
     * => 7  4
     * => 8  -1
     * => 9  5
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "  " << search(nums, i) << std::endl;
    }

    return 0;
}
