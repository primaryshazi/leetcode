#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(const std::string &s)
{
    std::unordered_set<char> unordered;
    int length = s.size();
    int end = -1;
    int max = 0;

    for (int i = 0; i < length; ++i)
    {
        // 当进行下一轮轮询之前删除上一字符
        if (i != 0)
        {
            unordered.erase(s[i - 1]);
        }
        // 字符不重复则继续记录字符
        while (end + 1 < length && unordered.count(s[end + 1]) == 0)
        {
            unordered.insert(s[end + 1]);
            ++end;
        }
        max = std::max(max, end - i + 1);
    }

    return max;
}

int main()
{
    std::string s1 = "abcabc";
    std::string s2 = "aabbcc";
    std::string s3 = "aabcddabcdeff";

    /**
     * => 3
     * => 2
     * => 6
     */
    std::cout << lengthOfLongestSubstring(s1) << std::endl;
    std::cout << lengthOfLongestSubstring(s2) << std::endl;
    std::cout << lengthOfLongestSubstring(s3) << std::endl;

    return 0;
}
