#include <iostream>
#include <cmath>
#include <cassert>

int simpleSort(int x)
{
    /**
     * f(x) = x ^ 2 - C
     * f'(X) = 2 * x
     *
     * 过(xi, xi ^ 2 - C)做一条斜率为2的直线，此直线与x轴的交点为近似解 x0 = 1 / 2 * (xi + C / xi)
     * 每一轮迭代会逼近于x，当两次迭代足够小时，认为已经达到了正解
     */
    assert(x >= 0);

    if (x == 0)
    {
        return 0;
    }

    double C = x;
    double x0 = x;

    while (true)
    {
        double xi = 0.5 * (x0 + C / x0);

        if (fabs(x0 - xi) < 1e-7)
        {
            break;
        }
        x0 = xi;
    }

    return static_cast<int>(x0);
}

int main()
{
    /**
     * => 10 3
     * => 20 4
     * => 30 5
     * => 40 6
     * => 50 7
     * => 60 7
     * => 70 8
     * => 80 8
     * => 90 9
     * => 100 10
     */
    for (int i = 0; i < 10; i++)
    {
        int value = (i + 1) * 10;
        std::cout << value << " " << simpleSort(value) << std::endl;
    }

    return 0;
}
