#include <iostream>
#include <string>

std::string countAndSay(int n)
{
    std::string prev = "1";

    for (int i = 1; i < n; i++)
    {
        std::string current;
        size_t start = 0;
        size_t pos = 0;

        // 遍历上一串
        while (pos < prev.size())
        {
            // 当前字符与开始字符相等时则步进
            while (pos < prev.size() && prev[start] == prev[pos])
            {
                ++pos;
            }
            // 当前串为start字符的数量加上start字符
            current += std::to_string(pos - start) + prev[start];
            start = pos;
        }
        prev = current;
    }

    return prev;
}

int main()
{
    /**
     * => 1
     * => 11
     * => 21
     * => 1211
     * => 111221
     * => 312211
     * => 13112221
     * => 1113213211
     * => 31131211131221
     * => 13211311123113112211
     */
    for (int i = 1; i <= 10; i++)
    {
        std::cout << countAndSay(i) << std::endl;
    }

    return 0;
}
