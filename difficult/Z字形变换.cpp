#include <iostream>
#include <string>
#include <vector>

std::string convert(const std::string &s, int numRows)
{
    if (numRows <= 1)
    {
        return s;
    }

    // 记录重拍之后每一行的字符
    std::vector<std::string> rowStr(std::min(numRows, static_cast<int>(s.size())));
    int cur = 0;            // 记录当前行
    bool isDown = false;    // 是否转向

    for (auto c : s)
    {
        rowStr[cur] += c;
        // 第一行或者最后一行时需要转向
        if (cur == 0 || cur == numRows - 1)
        {
            isDown = !isDown;
        }
        cur += isDown ? 1 : -1;
    }

    std::string result;
    for (auto &str : rowStr)
    {
        result += str;
    }

    return result;
}

int main()
{
    /**
     * => ABCDEFGHIJKLMN
     * => ACEGIKMBDFHJLN
     * => AEIMBDFHJLNCGK
     * => AGMBFHLNCEIKDJ
     * => AIBHJCGKDFLNEM
     */
    for (int i = 0; i < 5; i++)
    {
        std::cout << convert("ABCDEFGHIJKLMN", i + 1) << std::endl;
    }

    return 0;
}
