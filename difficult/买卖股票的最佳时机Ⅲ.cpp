#include <iostream>
#include <vector>

int maxProfit(const std::vector<int> &prices)
{
    size_t n = prices.size();
    int buy1 = prices[0];
    int sell1 = 0;
    int buy2 = prices[0];
    int sell2 = 0;
    for (size_t i = 1; i < n; ++i)
    {
        buy1 = std::min(buy1, prices[i]);
        sell1 = std::max(sell1, prices[i] - buy1);
        buy2 = std::min(buy2, prices[i] - sell1);
        sell2 = std::max(sell2, prices[i] - buy2);
    }

    return sell2;
}

int main()
{
    std::vector<int> p1 = { 1, 2, 3, 4, 5 };
    std::vector<int> p2 = { 5, 4, 3, 2, 1 };
    std::vector<int> p3 = { 2, 4, 1, 5, 3 };

    /**
     * => 4
     * => 0
     * => 6
     */
    std::cout << maxProfit(p1) << std::endl;
    std::cout << maxProfit(p2) << std::endl;
    std::cout << maxProfit(p3) << std::endl;

    return 0;
}
