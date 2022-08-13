#include <iostream>
#include <vector>

void visit(const std::vector<std::vector<char>> &grid, const size_t row, const size_t col, size_t i, size_t j, std::vector<std::vector<bool>> &isVisit)
{
    // 已被访问则退出
    if (isVisit[i][j])
    {
        return;
    }

    isVisit[i][j] = true;

    /**
     * 未达到上下左右边界且下一个点为1则继续访问
     */
    if (i > 0 && grid[i - 1][j] == '1')
    {
        visit(grid, row, col, i - 1, j, isVisit);
    }
    if (j > 0 && grid[i][j - 1] == '1')
    {
        visit(grid, row, col, i, j - 1, isVisit);
    }
    if (i < row - 1 && grid[i + 1][j] == '1')
    {
        visit(grid, row, col, i + 1, j, isVisit);
    }
    if (j < col - 1 && grid[i][j + 1] == '1')
    {
        visit(grid, row, col, i, j + 1, isVisit);
    }
}

int numIslands(std::vector<std::vector<char>> &grid)
{
    size_t row = grid.size();
    size_t col = grid[0].size();
    size_t count = 0;
    std::vector<std::vector<bool>> isVisit(row, std::vector<bool>(col, false));

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (grid[i][j] == '1' && !isVisit[i][j])
            {
                count++;
                visit(grid, row, col, i, j, isVisit);
            }
        }
    }

    return count;
}

int main()
{
    std::vector<std::vector<char>> grid = {
        {'1', '0', '1', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '1', '1', '1', '0'},
        {'0', '0', '0', '1', '1'},
        {'1', '1', '1', '0', '1'}
    };

    /**
     * => 4
     */
    std::cout << numIslands(grid) << std::endl;

    return 0;
}
