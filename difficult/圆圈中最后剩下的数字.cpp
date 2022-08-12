#include <iostream>

int lastRemaining(int n, int m)
{
    int x = 0;

    /**
     * 长度为n的序列会首先删除m % n个元素，下一个起始位置的值为x = m % n，余下长度为n - 1
     * 故n - 1的序列进行删除时，下一个起始位置的值为x = (x + m) % (n - 1)，
     * 当长度只有1时，洗一个起始位置的值即为最终结果0
     * f(1, m) = 0
     * f(2, m) = (f(1, m) + m) % 2
     * f(n, m) = (f(n - 1, m) + m) % n
     */
    for (int i = 2; i < n + 1; i++)
    {
        x = (m + x) % i;
    }

    return x;
}

int main()
{
    /**
     * => 0
     * => 1
     * => 1
     * => 0
     * => 3
     * => 0
     * => 3
     * => 6
     * => 0
     * => 3
     */
    for (int i = 1; i <= 10; i++)
    {
        std::cout << lastRemaining(i, 3) << std::endl;
    }

    return 0;
}