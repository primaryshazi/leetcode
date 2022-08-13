#include <iostream>
#include <vector>

int jump(const std::vector<int> &nums)
{
    int step = 0;
    int maxPos = 0;     // 当前位置下一步所能达到的最远处
    int nextPos = 0;    // 下一步的位置
    int len = static_cast<int>(nums.size());

    for (int i = 0; i < len - 1; ++i)
    {
        // 找到下一步最远的位置，然后到达该位置后记为一步
        if (maxPos >= i)
        {
            maxPos = std::max(maxPos, i + nums[i]);
            if (i == nextPos)
            {
                nextPos = maxPos;
                ++step;
            }
        }
    }

    return step;
}

int main()
{
    /**
     * => 3
     */
    std::cout << jump({ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8 }) << std::endl;

    return 0;
}
