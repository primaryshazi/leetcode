#include <iostream>
#include <vector>

void spiralOrderCore(std::vector<std::vector<int>> &matrix, int row, int column, int startRowIndex,
    int endRowIndex, int startColIndex, int endColIndex, std::vector<int> &result)
{
    /**
     * 打印一个周期，方式如下，从最左上角开始打印
     *
     * → → → ↓
     * ↑     ↓
     * ↑     ↓
     * ↑ ← ← ←
     *
     * → → → ↓
     * ↑ ← ← ←
     *
     * → → → →
     *
     * ↓
     * ↓
     * ↓
     * ↓
     */

    int rowIndex = startRowIndex;
    int colIndex = startColIndex;

    // 最上一行，从左向右
    while (colIndex < endColIndex)
    {
        result.emplace_back(matrix[rowIndex][colIndex]);
        ++colIndex;
    }

    // 最右一行，从上到下
    while (rowIndex < endRowIndex)
    {
        result.emplace_back(matrix[rowIndex][colIndex]);
        ++rowIndex;
    }

    // 如果只有一行或一列则直接输出当前，并退出
    if (startRowIndex == endRowIndex || startColIndex == endColIndex)
    {
        result.emplace_back(matrix[rowIndex][colIndex]);
        return;
    }

    // 最下一行，从右到左
    while (colIndex > startColIndex)
    {
        result.emplace_back(matrix[rowIndex][colIndex]);
        --colIndex;
    }

    // 最左一行，从下到上
    while (rowIndex > startRowIndex)
    {
        result.emplace_back(matrix[rowIndex][colIndex]);
        --rowIndex;
    }
}

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    if (matrix.empty())
    {
        return {};
    }

    int row = matrix.size();
    int column = matrix[0].size();
    int startRowIndex = 0;
    int endRowIndex = row - 1;
    int startColIndex = 0;
    int endColIndex = column - 1;
    std::vector<int> result;

    // 每次从最左上角开始，打印外圈，然后起点与终点均内移一位，打印内圈，循环往复
    while (startRowIndex <= endRowIndex && startColIndex <= endColIndex)
    {
        spiralOrderCore(matrix, row, column, startRowIndex, endRowIndex, startColIndex, endColIndex, result);
        ++startRowIndex;
        --endRowIndex;
        ++startColIndex;
        --endColIndex;
    }

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

int main()
{
    std::vector<std::vector<int>> v1 = {
            {1, 2, 3, 4}
    };
    std::vector<std::vector<int>> v2 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8}
    };
    std::vector<std::vector<int>> v3 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    std::vector<std::vector<int>> v4 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15 , 16}
    };
    std::vector<std::vector<int>> v5 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
            {17, 18, 19, 20}
    };

    /**
     * => { 1, 2, 3, 4 }
     * => { 1, 2, 3, 4, 8, 7, 6, 5 }
     * => { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 }
     * => { 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10 }
     * => { 1, 2, 3, 4, 8, 12, 16, 20, 19, 18, 17, 13, 9, 5, 6, 7, 11, 15, 14, 10 }
     */
    std::cout << spiralOrder(v1) << std::endl;
    std::cout << spiralOrder(v2) << std::endl;
    std::cout << spiralOrder(v3) << std::endl;
    std::cout << spiralOrder(v4) << std::endl;
    std::cout << spiralOrder(v5) << std::endl;

    return 0;
}
