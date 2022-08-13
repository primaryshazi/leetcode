#include <iostream>
#include <vector>
#include <algorithm>

int findRadius(std::vector<int> &houses, std::vector<int> &heaters)
{
    std::sort(heaters.begin(), heaters.end());
    int heaterLen = static_cast<int>(heaters.size());
    int minRadius = 0;

    // 任何一个房间的最小半径必然是距离左右喷头的最小值，所有房间的最小半径则是所有最小值的最大者
    for (auto pos : houses)
    {
        // 获取右边喷头的索引
        auto index = std::upper_bound(heaters.begin(), heaters.end(), pos) - heaters.begin();
        // 距离右边喷头的距离
        int right = index >= heaterLen ? INT_MAX : heaters[index] - pos;
        // 距离左边喷头的距离
        int left = index > 0 ? pos - heaters[index - 1] : INT_MAX;
        minRadius = std::max(std::min(right, left), minRadius);
    }

    return minRadius;
}


int main()
{
    std::vector<int> houses = { 2, 5, 9, 12 };
    std::vector<int> heaters = { 1, 4, 10 };

    /**
     * => 2
     */
    std::cout << findRadius(houses, heaters) << std::endl;

    return 0;
}
