#include <iostream>
#include <vector>

std::vector<int> plusOne(const std::vector<int> &digits)
{
    int length = digits.size();
    int index = length - 1;
    std::vector<int> result;

    // 从右边起第一不为9的值，将此值加1，右边的9均置为0
    while (index >= 0 && digits[index] == 9)
    {
        index--;
    }

    if (index < 0)
    {
        result.assign(length + 1, 0);
        result[0] = 1;
    }
    else
    {
        result.assign(length, 0);
        for (int i = 0; i <= index; i++)
        {
            result[i] = digits[i];
        }
        result[index] += 1;
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
    std::vector<int> v1 = { 1, 2, 3, 4 };
    std::vector<int> v2 = { 1, 2, 3, 9 };
    std::vector<int> v3 = { 1, 2, 9, 9 };
    std::vector<int> v4 = { 1, 9, 9, 9 };
    std::vector<int> v5 = { 9, 9, 9, 9 };

    /**
     * => { 1, 2, 3, 5 }
     * => { 1, 2, 4, 0 }
     * => { 1, 3, 0, 0 }
     * => { 2, 0, 0, 0 }
     * => { 1, 0, 0, 0, 0 }
     */
    std::cout << plusOne(v1) << std::endl;
    std::cout << plusOne(v2) << std::endl;
    std::cout << plusOne(v3) << std::endl;
    std::cout << plusOne(v4) << std::endl;
    std::cout << plusOne(v5) << std::endl;

    return 0;
}
