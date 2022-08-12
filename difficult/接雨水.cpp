#include <iostream>
#include <vector>

int trap(const std::vector<int> &height)
{
    int n = static_cast<int>(height.size());
    if (n == 0)
    {
        return 0;
    }

    std::vector<int> leftMax(n, 0);
    std::vector<int> rightMax(n, 0);

    // 从左向右遍历，获取每一格的最大高度
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = std::max(leftMax[i - 1], height[i]);
    }

    // 从右向左遍历，获取每一格的最大高度
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = std::max(rightMax[i + 1], height[i]);
    }

    // 二者取并集，并减去所占高度，即该格可容纳高度
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        max += std::min(leftMax[i], rightMax[i]) - height[i];
    }

    return max;
}

int main()
{
    /**
     * => 6
     * => 9
     */
    std::cout << trap({ 0,1,0,2,1,0,1,3,2,1,2,1 }) << std::endl;
    std::cout << trap({ 4,2,0,3,2,5 }) << std::endl;

    return 0;
}
