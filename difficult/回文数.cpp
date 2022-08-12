#include <iostream>

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int revertedNumber = 0;

    // 将数字后半部分进行翻转，若后者翻转后大于前者则翻装完成
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    /**
     * xyyx xyzyx
     * 当数字位数为偶数时，xy == xy，前者可判断
     * 当数字位数为奇数时，xy == xyz，后者可判断
     */
    return x == revertedNumber || x == revertedNumber / 10;
}

int main()
{
    /**
     * => 0
     * => 1
     * => 1
     * => 1
     * => 0
     */
    std::cout << isPalindrome(-999) << std::endl;
    std::cout << isPalindrome(0) << std::endl;
    std::cout << isPalindrome(123454321) << std::endl;
    std::cout << isPalindrome(1234554321) << std::endl;
    std::cout << isPalindrome(123456789) << std::endl;

    return 0;
}
