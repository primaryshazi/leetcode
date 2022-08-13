#include <iostream>

int numWays(int n)
{
    if (n < 2)
    {
        return 1;
    }
    int x = 0;
    int y = 1;
    int z = 1;
    for (int i = 2; i <= n; i++)
    {
        x = y;
        y = z;
        z = (x + y) % 1000000007;
    }

    return z;
}

int main()
{
    /**
     * => 1
     * => 1
     * => 2
     * => 3
     * => 5
     * => 8
     * => 13
     * => 21
     * => 34
     * => 55
     * => 89
     * => 144
     * => 233
     * => 377
     * => 610
     * => 987
     * => 1597
     * => 2584
     * => 4181
     * => 6765
     */
    for (int i = 0; i < 20; i++)
    {
        std::cout << numWays(i) << std::endl;
    }

    return 0;
}
