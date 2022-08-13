#include <iostream>
#include <string>
#include <vector>

int strStr(const std::string &source, const std::string &target)
{
    int n = source.size();
    int m = target.size();

    if (m == 0)
    {
        return 0;
    }

    std::vector<int> next(m);

    /**
     * 从第2个字符开始与第1个开始比较，得出到每一个字符为止的前缀重复字串长度
     * 若当前字符与前字符不等则将前缀长度回滚到出现有前缀相等的位置
     * 若当前字符与前字符相等则将前缀长度加1
     */
    for (int cur = 1, pre = 0; cur < m; cur++)
    {
        while (pre > 0 && target[cur] != target[pre])
        {
            pre = next[pre - 1];
        }
        if (target[cur] == target[pre])
        {
            pre++;
        }
        next[cur] = pre;
    }

    /**
     * 利用next数组进行匹配，当出现有字符不匹配时，直接追溯到上一个有匹配的位置
     * 若字符匹配则将匹配索引加1
     */
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && source[i] != target[j])
        {
            j = next[j - 1];
        }
        if (source[i] == target[j])
        {
            j++;
        }
        if (j == m)
        {
            return i - m + 1;
        }
    }

    return -1;
}

int main()
{
    std::string source = "abccabababaaababaaacbcbabac";
    std::string target = "ababaaababaa";

    /**
     * => 6
     */
    std::cout << strStr(source, target) << std::endl;

    return 0;
}
