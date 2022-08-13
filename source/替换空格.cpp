#include <iostream>
#include <string>

std::string replaceSpace(const std::string &s)
{
    size_t spaceNum = 0;
    size_t sLen = s.length();

    // 计算空白字符的长度
    for (auto c : s)
    {
        if (std::isspace(c))
        {
            spaceNum++;
        }
    }

    // 提前申请指定长度的字符串
    size_t rLen = sLen + spaceNum * 2;
    std::string result(rLen, '\0');

    // 将c中字符全部拷贝过来
    int index = 0;
    for (auto c : s)
    {
        if (std::isspace(c))
        {
            result[index++] = '%';
            result[index++] = '2';
            result[index++] = '0';
        }
        else
        {
            result[index] = c;
            index++;
        }
    }

    return result;
}

int main()
{
    /**
     * => Hello%20World!%20Are%20You%20OK?
     */
    std::cout << replaceSpace("Hello World! Are You OK?") << std::endl;

    return 0;
}
