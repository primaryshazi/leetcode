#include <iostream>
#include <vector>

int uniquePathsWithObstacles(const std::vector<std::vector<int>> &obstacleGrid)
{
    int row = static_cast<int>(obstacleGrid.size());
    if (row == 0)
    {
        return 0;
    }

    int column = static_cast<int>(obstacleGrid[0].size());
    if (column == 0)
    {
        return 0;
    }

    if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][column - 1] == 1)
    {
        return 0;
    }

    std::vector<std::vector<int>> dp(row, std::vector<int>(column, 0));

    for (int i = 0; i < row; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            break;
        }
        dp[i][0] = 1;
    }

    for (int i = 0; i < column; i++)
    {
        if (obstacleGrid[0][i] == 1)
        {
            break;
        }
        dp[0][i] = 1;
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < column; j++)
        {
            if (obstacleGrid[i][j] == 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return dp[row - 1][column - 1];
}

int main()
{
    std::vector<std::vector<int>> obstacleGrid = {
        { 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0 }
    };

    /**
     * => 7
     */
    std::cout << uniquePathsWithObstacles(obstacleGrid) << std::endl;

    return 0;
}
