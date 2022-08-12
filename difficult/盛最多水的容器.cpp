#include <iostream>
#include <vector>

int maxArea(const std::vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int max = 0;

    while (left < right)
    {
        // 索引之差乘以较小值为面积
        int area = (right - left) * std::min(height[left], height[right]);

        if (area > max)
        {
            max = area;
        }

        // 值较小者移动索引
        if (height[left] < height[right])
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    return max;
}

int main()
{
    /**
     * => 20
     * => 10
     * => 8
     */
    std::cout << maxArea({ 5, 3, 1, 8, 6, 4 }) << std::endl;
    std::cout << maxArea({ 1, 3, 5, 7, 9 }) << std::endl;
    std::cout << maxArea({ 8, 6, 4, 2, 0 }) << std::endl;

    return 0;
}
