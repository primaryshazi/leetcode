#include <iostream>
#include <string>
#include <algorithm>

std::string addStrings(std::string &sLeft, std::string &sRight)
{
    std::string result;
    int leftIndex = sLeft.length() - 1;
    int rightIndex = sRight.length() - 1;
    int carry = 0;   // 进数

    while (leftIndex >= 0 || rightIndex >= 0)
    {
        int x = leftIndex >= 0 ? sLeft[leftIndex] - '0' : 0;
        int y = rightIndex >= 0 ? sRight[rightIndex] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        result += '0' + sum % 10;
        leftIndex--;
        rightIndex--;
    }
    if (carry > 0)
    {
        result += '0' + carry;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::string s1 = "12345";
    std::string s2 = "987654321";
    std::string s3 = "111111";
    std::string s4 = "99999999";

    /**
     * => 12345 + 987654321 = 987666666
     * => 111111 + 99999999 = 100111110
     */
    std::cout << s1 << " + " << s2 << " = " << addStrings(s1, s2) << std::endl;
    std::cout << s3 << " + " << s4 << " = " << addStrings(s3, s4) << std::endl;

    return 0;
}
