#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(const std::string &s)
{
    int start = -1;
    int result = 0;
    int length = static_cast<int>(s.size());
    std::unordered_map<char, int> unorder;  // 记录每个字符出现的位置

    for (int i = 0; i < length; i++)
    {
        /**
         * 若字符不存在则记录字符
         * 若字符存在则更新开始记录位置和字符上次出现的位置
         */
        if (unorder.count(s[i]) == 0)
        {
            unorder.emplace(std::make_pair(s[i], i));
        }
        else
        {
            start = std::max(start, unorder[s[i]]);
            unorder[s[i]] = i;
        }
        result = std::max(result, i - start);
    }

    return result;
}

int main()
{
    /**
     * => 3
     * => 3
     * => 1
     */
    std::cout << lengthOfLongestSubstring("abcabcabb") << std::endl;
    std::cout << lengthOfLongestSubstring("abcbbb") << std::endl;
    std::cout << lengthOfLongestSubstring("aaaa") << std::endl;

    return 0;
}
