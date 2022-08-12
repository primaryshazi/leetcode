#include <iostream>

int climbStairs(int n)
{
    int x = 0;
    int y = 0;
    int z = 1;

    for (int i = 1; i <= n; i++)
    {
        x = y;
        y = z;
        z = x + y;
    }

    return z;
}

int main()
{
    /**
     * => 0  1
     * => 1  1
     * => 2  2
     * => 3  3
     * => 4  5
     * => 5  8
     * => 6  13
     * => 7  21
     * => 8  34
     * => 9  55
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "  " << climbStairs(i) << std::endl;
    }

    return 0;
}
