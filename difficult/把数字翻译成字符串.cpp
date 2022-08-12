#include <iostream>

int translateNum(int num)
{
    if (num <= 9)
    {
        return 1;
    }
    int ba = num % 100; // 每次最多比较两位

    /**
     * 若该值只有一位，或超过上线则只能计算一位
     * 否则可以分为一位或者两位进行计算
     */
    if (ba <= 9 || ba >= 26)
    {
        return translateNum(num / 10);
    }
    else
    {
        return translateNum(num / 10) + translateNum(num / 100);
    }
}

int main()
{
    /**
     * => 4
     * => 1
     * => 3
     */
    std::cout << translateNum(1024) << std::endl;
    std::cout << translateNum(996) << std::endl;
    std::cout << translateNum(1234567890) << std::endl;

    return 0;
}
