#include <iostream>

bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    /**
     * => 1  1
     * => 2  1
     * => 3  0
     * => 4  1
     * => 5  0
     * => 6  0
     * => 7  0
     * => 8  1
     * => 9  0
     * => 10  0
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << i + 1 << "  " << isPowerOfTwo(i + 1) << std::endl;
    }

    return 0;
}
