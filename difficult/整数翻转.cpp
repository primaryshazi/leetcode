#include <iostream>

int reverse(int x)
{
    int result = 0;

    while (x != 0)
    {
        // 防止数据溢出
        if (result < INT_MIN / 10 || result > INT_MAX / 10)
        {
            return 0;
        }

        int digit = x % 10;           // 取出个位数
        x /= 10;                      // 除去各位数
        result = result * 10 + digit; // 将x的个位数加入result的个位
    }

    return result;
}

int main()
{
    /**
     * => 54321
     * => -6789
     * => 0
     * => 9
     */
    std::cout << reverse(12345) << std::endl;
    std::cout << reverse(-9876) << std::endl;
    std::cout << reverse(0) << std::endl;
    std::cout << reverse(9) << std::endl;

    return 0;
}
