#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix)
{
    size_t length = matrix.size();

    // 先上下翻转
    for (size_t i = 0; i < length / 2; i++)
    {
        matrix[i].swap(matrix[length - 1 - i]);
    }

    // 后对角反转
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = i; j < length; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
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
    std::vector<std::vector<int>> matrix = {
        { 0, 1, 2, 3, 4 },
        { 5, 6, 7, 8, 9 },
        { 10, 11, 12, 13, 14 },
        { 15, 16, 17, 18, 19 },
        { 20, 21, 22, 23, 24 }
    };

    /**
     * => { { 20, 15, 10, 5, 0 },
     *      { 21, 16, 11, 6, 1 },
     *      { 22, 17, 12, 7, 2 },
     *      { 23, 18, 13, 8, 3 },
     *      { 24, 19, 14, 9, 4 } }
     */
    rotate(matrix);

    std::cout << matrix << std::endl;

    return 0;
}
