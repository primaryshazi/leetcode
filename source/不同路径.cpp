#include <iostream>
#include <vector>

int uniquePaths(int m, int n)
{
    if (m <= 0 || n <= 0)
    {
        return 0;
    }

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
    /**
     * => 0
     * => 1
     * => 3
     * => 10
     * => 35
     * => 126
     * => 462
     * => 1716
     * => 6435
     * => 24310
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << uniquePaths(i, i + 1) << std::endl;
    }

    return 0;
}
