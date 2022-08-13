#include <iostream>
#include <vector>

int coinChange(const std::vector<int> &coins, int amount)
{
    int maxVal = amount + 1;
    std::vector<int> dp(amount + 1, maxVal);    // 记录每一个金额所需要的最小数量

    dp[0] = 0;
    for (auto coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    /**
     * => 3
     * => 4
     * => 7
     */
    std::cout << coinChange({ 1, 2, 5 }, 11) << std::endl;
    std::cout << coinChange({ 1, 2, 5 }, 17) << std::endl;
    std::cout << coinChange({ 1, 2, 5 }, 31) << std::endl;

    return 0;
}
