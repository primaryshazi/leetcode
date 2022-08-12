#include <iostream>
#include <vector>

int search(const std::vector<int> &nums, int target)
{
    int length = nums.size();
    if (length == 0)
    {
        return -1;
    }
    if (1 == length)
    {
        return nums[0] == target ? 0 : -1;
    }

    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // 中值大于等于首值则左子串必为全有序，否则左子串可能有序
        if (nums[0] <= nums[mid])
        {
            // 在全有序中，目标值若在其中则必然处于左右两端值之间
            if (nums[0] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            // 在可能有序中，目标值若处于左右两端值之间，则右子数组必然全有序
            if (nums[mid] < target && target <= nums[length - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    std::vector<int> v = { 3, 4, 5, 1, 2 };

    /**
     * => 0  -1
     * => 1  3
     * => 2  4
     * => 3  0
     * => 4  1
     * => 5  2
     * => 6  -1
     */
    for (int i = 0; i <= v.size() + 1; i++)
    {
        std::cout << i << "  " << search(v, i) << std::endl;
    }

    return 0;
}
