#include <iostream>
#include <vector>

int getPos(int x)
{
    int total = 0;
    for (; x > 0; x /= 10)
    {
        total += x % 10;
    }
    return total;
}

int movingCount(int m, int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    std::vector<std::vector<int>> visitor(m, std::vector<int>(n, 0));   // 标记该位置是否可达
    int result = 1;

    visitor[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 起始位置或者超过最大值则跳过
            if ((i == 0 && j == 0) || (getPos(i) + getPos(j) > k))
            {
                continue;
            }

            // (i, j)只能由(i - 1, j)或者(i, j - 1)到达，故这两点有任意一点可达则(i, j)必定可达
            if (i - 1 >= 0)
            {
                visitor[i][j] |= visitor[i - 1][j];
            }
            if (j - 1 >= 0)
            {
                visitor[i][j] |= visitor[i][j - 1];
            }
            result += visitor[i][j];
        }
    }

    return result;
}

int main()
{
    /**
     * => 64
     * => 21
     * => 3
     */
    std::cout << movingCount(10, 10, 10) << std::endl;
    std::cout << movingCount(10, 10, 5) << std::endl;
    std::cout << movingCount(10, 10, 1) << std::endl;

    return 0;
}
