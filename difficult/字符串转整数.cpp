#include <iostream>
#include <string>

int myAtoi(const std::string &s)
{
    int64_t result = 0;
    int sign = 0;   // 标记正负数，无符号位时默认为正数

    for (auto ch : s)
    {
        if (ch == '+' || ch == '-')
        {
            if (sign != 0)
            {
                break;
            }
            sign = ch == '+' ? 1 : -1;
        }
        else if (std::isspace(ch))
        {
            if (sign != 0)
            {
                break;
            }
            continue;
        }
        else if (std::isdigit(ch))
        {
            if (sign == 0)
            {
                sign = 1;
            }
            result = result * 10 + sign * (ch - '0');

            if (result > INT_MAX)
            {
                result = INT_MAX;
                break;
            }
            if (result < INT_MIN)
            {
                result = INT_MIN;
                break;
            }
        }
        else
        {
            break;
        }
    }

    return result;
}

int main()
{
    /**
     * => 0
     * => 123
     * => -123
     * => 123
     * => 123
     * => 123
     * => 2147483647
     * => -2147483648
     */
    std::cout << myAtoi("a123") << std::endl;
    std::cout << myAtoi("   +123") << std::endl;
    std::cout << myAtoi("   -123") << std::endl;
    std::cout << myAtoi("123a456") << std::endl;
    std::cout << myAtoi("123+456") << std::endl;
    std::cout << myAtoi(" 123 456 ") << std::endl;
    std::cout << myAtoi("+12345678987654321") << std::endl;
    std::cout << myAtoi("-12345678987654321") << std::endl;

    return 0;
}
