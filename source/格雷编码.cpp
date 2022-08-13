#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> grayCode(int n)
{
    if (n <= 0)
    {
        return {};
    }

    int length = 1 << n;
    std::vector<int> code(length, 0);

    for (int i = 0; i < length; i++)
    {
        code[i] = (i >> 1) ^ i;
    }

    return code;
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
     * => { 0, 1 }
     * => { 0, 1, 3, 2 }
     * => { 0, 1, 3, 2, 6, 7, 5, 4 }
     * => { 0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8 }
     * => { 0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8, 24, 25, 27, 26, 30, 31, 29, 28, 20, 21, 23, 22, 18, 19, 17, 16 }
     */
    for (int i = 0; i <= 5; i++)
    {
        std::cout << grayCode(i) << std::endl;
    }

    return 0;
}
