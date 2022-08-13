#include <iostream>
#include <vector>

int maxProfit(const std::vector<int> &prices)
{
    int maxPro = 0;
    int length = static_cast<int>(prices.size());
    for (int i = 1; i < length; ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            maxPro += prices[i] - prices[i - 1];
        }
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
     * => 6
     */
    std::cout << maxProfit(p1) << std::endl;
    std::cout << maxProfit(p2) << std::endl;
    std::cout << maxProfit(p3) << std::endl;

    return 0;
}
