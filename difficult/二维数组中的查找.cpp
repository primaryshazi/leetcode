#include <iostream>
#include <vector>

bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target)
{
    int row = static_cast<int>(matrix.size());
    if (0 == row)
    {
        return false;
    }

    int col = static_cast<int>(matrix[0].size());
    if (0 == col)
    {
        return false;
    }

    int r = 0;
    int c = col - 1;
    // 从第一行的最后一列开始查找
    while (r < row && c >= 0)
    {
        int value = matrix[r][c];

        /**
         * 当前值比目标值大则减少一列，查找左列
         * 当前值比目标值小则增加一行，查找下行
         */
        if (value > target)
        {
            --c;
        }
        else if (value < target)
        {
            ++r;
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        { 1, 3, 5 },
        { 4, 6, 8 },
        { 7, 8, 9 }
    };

    /**
     * => 0 false
     * => 1 true
     * => 2 false
     * => 3 true
     * => 4 true
     * => 5 true
     * => 6 true
     * => 7 true
     * => 8 true
     * => 9 true
     */
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " " << (findNumberIn2DArray(matrix, i) ? "true" : "false") << std::endl;
    }

    return 0;
}
