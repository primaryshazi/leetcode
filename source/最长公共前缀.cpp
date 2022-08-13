#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(const std::vector<std::string> &vec)
{
    if (vec.empty())
    {
        return "";
    }

    size_t size = vec.size();
    size_t length = vec.at(0).length();

    for (size_t i = 0; i < length; i++)
    {
        auto &c = vec.at(0).at(i);
        for (size_t j = 1; j < size; j++)
        {
            // 若当前字符串的长度与等于比较索引或者字符串指定索引处字符不等则比较结束
            if (vec.at(j).length() == i || vec.at(j).at(i) != c)
            {
                return vec.at(0).substr(0, i);
            }
        }
    }

    return vec.at(0);
}

int main()
{
    std::vector<std::string> vec1 = { "abcdefg", "abcde", "abc", "abcdefg" };
    std::vector<std::string> vec2 = { "abcdefg", "abcde", "abc", "abcdefg", "" };
    std::vector<std::string> vec3 = { "abcdefg", "abcde", "abc", "abcdefg", "efg" };

    /**
     * => [abc]
     * => []
     * => []
     */
    std::cout << "[" << longestCommonPrefix(vec1) << "]" << std::endl;
    std::cout << "[" << longestCommonPrefix(vec2) << "]" << std::endl;
    std::cout << "[" << longestCommonPrefix(vec3) << "]" << std::endl;

    return 0;
}
