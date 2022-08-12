#include <iostream>
#include <string>
#include <vector>

std::string multiply(const std::string &num1, const std::string &num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }

    int len1 = static_cast<int>(num1.size());
    int len2 = static_cast<int>(num2.size());
    std::vector<int> vMulti(len1 + len2, 0);

    // 将每一位乘积结果放入到指定位置
    for (int i = len1 - 1; i >= 0; --i)
    {
        int x = num1[i] - '0';
        for (int j = len2 - 1; j >= 0; --j)
        {
            int y = num2[j] - '0';
            vMulti[i + j + 1] += x * y;
        }
    }

    // 处理数据进位
    for (int i = len1 + len2 - 1; i > 0; --i)
    {
        vMulti[i - 1] += vMulti[i] / 10;
        vMulti[i] %= 10;
    }

    int index = vMulti[0] == 0 ? 1 : 0; // 判断结果起始位置
    std::string sMulti;

    // 将结果写入到字符串内
    while (index < len1 + len2)
    {
        sMulti.push_back('0' + vMulti[index]);
        ++index;
    }

    return sMulti;
}

int main()
{
    /**
     * => 1524074060205
     */
    std::cout << multiply("12345", "123456789") << std::endl;

    return 0;
}
