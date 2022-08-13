#include <iostream>
#include <vector>

int maxProfit(const std::vector<int> &prices)
{
    int minPri = INT_MAX;   // 记录历史最低价格
    int maxPro = 0;         // 记录当前最高收益

    for (auto p : prices)
    {
        maxPro = std::max(maxPro, p - minPri);
        minPri = std::min(p, minPri);
    }

    return maxPro;
}

int main()
{
    std::vector<int> p1 = { 1, 2, 3, 4, 5 };
    std::vector<int> p2 = { 5, 4, 3, 2, 1 };
    std::vector<int> p3 = { 2, 4, 1, 5, 3 };

    /**
     * => 4
     * => 0
     * => 4
     */
    std::cout << maxProfit(p1) << std::endl;
    std::cout << maxProfit(p2) << std::endl;
    std::cout << maxProfit(p3) << std::endl;

    return 0;
}
