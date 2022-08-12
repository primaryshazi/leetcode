#include <iostream>

int divide(int a, int b)
{
    if (a == INT_MIN && b == -1)
    {
        return INT_MAX;
    }
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;

    unsigned ua = std::abs(a);
    unsigned ub = std::abs(b);
    unsigned result = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((ua >> i) >= ub)
        {
            ua -= (ub << i);
            result += (1 << i);
        }
    }

    return sign == 1 ? result : -result;
}

int main()
{
    /**
     * => 11
     * => -11
     * => -11
     * => 11
     */
    std::cout << divide(100, 9) << std::endl;
    std::cout << divide(-100, 9) << std::endl;
    std::cout << divide(100, -9) << std::endl;
    std::cout << divide(-100, -9) << std::endl;

    return 0;
}
