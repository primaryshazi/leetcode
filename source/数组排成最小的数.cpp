#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string minNumber(std::vector<int> &nums)
{
    // 转为字符串，若xy < yx则x在前
    std::sort(nums.begin(), nums.end(), [](const auto &x, const auto &y) {
        auto sx = std::to_string(x);
        auto sy = std::to_string(y);
        return (sx + sy) < (sy + sx);
        });
    std::string result;
    for (auto i : nums)
    {
        result += std::to_string(i);
    }

    return result;
}

int main()
{
    std::vector<int> v1 = { 3, 30, 34, 5, 9 };
    std::vector<int> v2 = { 0, 2, 5, 13, 41, 1, 0, 0 };

    /**
     * => 3033459
     * => 0001132415
     */
    std::cout << minNumber(v1) << std::endl;
    std::cout << minNumber(v2) << std::endl;

    return 0;
}
