#include <iostream>
#include <string>
#include <utility>

std::pair<int, int> expandAround(const std::string &s, int left, int right)
{
    // 由中心向两端扩张，左右分位分别相等则必为回文
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        --left;
        ++right;
    }

    return std::make_pair(left + 1, right - 1);
}

std::string longestPalindrome(const std::string &s)
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // 奇数回文子串
        auto [leftOdd, rightOdd] = expandAround(s, i, i);
        // 偶数回文子串
        auto [leftEven, rightEven] = expandAround(s, i, i + 1);

        if (rightOdd - leftOdd > end - start)
        {
            end = rightOdd;
            start = leftOdd;
        }
        if (rightEven - leftEven > end - start)
        {
            end = rightEven;
            start = leftEven;
        }
    }

    return s.substr(start, end - start + 1);
}

int main()
{
    /**
     * => a
     * => bb
     * => bcb
     * => ccabacc
     */
    std::cout << longestPalindrome("abc") << std::endl;
    std::cout << longestPalindrome("abbc") << std::endl;
    std::cout << longestPalindrome("abcbca") << std::endl;
    std::cout << longestPalindrome("abccbabcc") << std::endl;

    return 0;
}
