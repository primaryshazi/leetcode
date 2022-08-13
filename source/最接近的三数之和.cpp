#include <iostream>
#include <algorithm>
#include <vector>

int threeSumClosest(std::vector<int> &nums, int target)
{
    int length = static_cast<int>(nums.size());
    int64_t vResult = INT_MAX;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < length; ++i)
    {
        // 当非第一轮且当前元素与上一元素相同则不处理
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = length - 1;

        // 利用双指针
        while (j < k)
        {
            int value = nums[i] + nums[j] + nums[k];
            if (value == target)
            {
                return target;
            }

            // 记录最好的结果
            if (std::abs(value - target) < std::abs(vResult - target))
            {
                vResult = value;
            }

            /**
             * 找到第一个不与本身相同的下一个值
             * 当值比目标值大时，需要向前移动k，使值变小
             * 当值比目标值小时，需要向后移动j，使值变大
             */
            if (value > target)
            {
                int x = k - 1;
                // 跳过相同的数值
                while (j < x && nums[x] == nums[k])
                {
                    --x;
                }
                k = x;
            }
            else
            {
                int x = j + 1;
                // 跳过相同的数值
                while (x < k && nums[x] == nums[j])
                {
                    ++x;
                }
                j = x;
            }
        }
    }

    return vResult;
}

int main()
{
    std::vector<int> vec = { -5, -3, -3, -1, 1, 3, 3, 3 };

    /**
     * => 0  -1
     * => 1  1
     * => 2  1
     * => 3  3
     * => 4  3
     * => 5  5
     * => 6  5
     * => 7  7
     * => 8  7
     * => 9  9
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "  " << threeSumClosest(vec, i) << std::endl;
    }

    return 0;
}
