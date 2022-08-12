#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n)
{
    if (n <= 0)
    {
        return {};
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int startRowIndex = 0;
    int endRowIndex = n - 1;
    int startColIndex = 0;
    int endColIndex = n - 1;
    int num = 1;

    // 每次从最左上角开始，打印外圈，然后起点与终点均内移一位，打印内圈，循环往复
    while (startRowIndex <= endRowIndex && startColIndex <= endColIndex)
    {
        do
        {
            int rowIndex = startRowIndex;
            int colIndex = startColIndex;

            // 最上一行，从左向右
            while (colIndex < endColIndex)
            {
                matrix[rowIndex][colIndex] = num++;
                ++colIndex;
            }

            // 最右一行，从上到下
            while (rowIndex < endRowIndex)
            {
                matrix[rowIndex][colIndex] = num++;
                ++rowIndex;
            }

            // 如果只有一行或一列则直接输出当前，并退出
            if (startRowIndex == endRowIndex || startColIndex == endColIndex)
            {
                matrix[rowIndex][colIndex] = num++;
                break;
            }

            // 最下一行，从右到左
            while (colIndex > startColIndex)
            {
                matrix[rowIndex][colIndex] = num++;
                --colIndex;
            }

            // 最左一行，从下到上
            while (rowIndex > startRowIndex)
            {
                matrix[rowIndex][colIndex] = num++;
                --rowIndex;
            }
        } while (false);

        ++startRowIndex;
        --endRowIndex;
        ++startColIndex;
        --endColIndex;
    }

    return matrix;
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
    /**
     * => {  }
     *
     * => { { 1 } }
     *
     * => { { 1, 2 },
     *      { 4, 3 } }
     *
     * => { { 1, 2, 3 },
     *      { 8, 9, 4 },
     *      { 7, 6, 5 } }
     *
     * => { { 1, 2, 3, 4 },
     *      { 12, 13, 14, 5 },
     *      { 11, 16, 15, 6 },
     *      { 10, 9, 8, 7 } }
     */
    for (int i = 0; i < 5; i++)
    {
        std::cout << generateMatrix(i) << std::endl;
    }

    return 0;
}
