#include <iostream>

int countEven(int num)
{
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        int sum = 0;
        int tmp = i;
        while (tmp > 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }

        if ((sum & 01) == 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    /**
     * => 0
     * => 4
     * => 10
     * => 14
     * => 20
     * => 24
     * => 30
     * => 34
     * => 40
     * => 44
     */
    for (int i = 0; i < 100; i += 10)
    {
        std::cout << countEven(i) << std::endl;
    }

    return 0;
}
