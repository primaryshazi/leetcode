#include <iostream>
#include <algorithm>
#include <string>

std::string addBinary(const std::string &a, const std::string &b)
{
    std::string result;
    std::string sa = a;
    std::string sb = b;
    size_t aLen = sa.length();
    size_t bLen = sb.length();

    std::reverse(sa.begin(), sa.end());
    std::reverse(sb.begin(), sb.end());

    int maxLen = std::max(aLen, bLen);
    int value = 0;

    for (size_t i = 0; i < maxLen; ++i)
    {
        // 当未超过sa长度时，若当前字符为1，则当前值加1，否则为0
        value += i < aLen ? (sa.at(i) == '1') : 0;
        // 当未超过sb长度时，若当前字符为1，则当前值加1，否则为0
        value += i < bLen ? (sb.at(i) == '1') : 0;
        // 若当前值为2时则补0，否则补1
        result.push_back((value % 2) ? '1' : '0');
        value /= 2;
    }

    if (value)
    {
        result.push_back('1');
    }
    std::reverse(result.begin(), result.end());

    return result;
}

int main()
{
    std::string a = "11111";
    std::string b = "1111";
    std::string c = "1000";

    /**
     * => 101110
     * => 10111
     * => 100111
     */
    std::cout << addBinary(a, b) << std::endl;
    std::cout << addBinary(b, c) << std::endl;
    std::cout << addBinary(c, a) << std::endl;

    return 0;
}
