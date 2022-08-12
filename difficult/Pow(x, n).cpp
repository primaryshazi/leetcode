#include <iostream>

double quickMul(double x, int64_t N)
{
    double ans = 1.0;
    double mult = x;

    while (N > 0)
    {
        // 若指数为基数则乘以累计值
        if (N % 2 == 1)
        {
            ans *= mult;
        }

        // 累计平方，指数减半
        mult *= mult;
        N /= 2;
    }

    return ans;
}

double myPow(double x, int n)
{
    int64_t N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}

int main()
{
    /**
     * => 0  1
     * => 1  2
     * => 2  4
     * => 3  8
     * => 4  16
     * => 5  32
     * => 6  64
     * => 7  128
     * => 8  256
     * => 9  512
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "  " << myPow(2, i) << std::endl;
    }

    return 0;
}
