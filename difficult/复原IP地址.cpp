#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> result;

void backtrace(const std::string &s, size_t cur, size_t index, std::string &str)
{
    if (cur == 4 || index == s.size())
    {
        if (cur == 4 && index == s.size())
        {
            result.push_back(str.substr(0, str.size() - 1));
        }
        return;
    }

    for (size_t i = 1; i <= 3 && index + i <= s.size();i++)
    {
        // 不存在0开头的两位以上
        if (s[index] == '0' && i != 1)
        {
            return;
        }

        if (i == 3 && s.substr(index, i) > "255")
        {
            return;
        }

        str += s.substr(index, i);
        str.push_back('.');
        backtrace(s, cur + 1, index + i, str);
        str = str.substr(0, str.size() - i - 1);
    }
}

std::vector<std::string> restoreIpAddresses(const std::string &s)
{
    std::string str;
    result.clear();
    backtrace(s, 0, 0, str);
    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

int main()
{
    /**
     * => { 1.3.5.79, 1.3.57.9, 1.35.7.9, 13.5.7.9 }
     * => { 0.2.4.68, 0.2.46.8, 0.24.6.8 }
     */
    std::cout << restoreIpAddresses("13579") << std::endl;
    std::cout << restoreIpAddresses("002468") << std::endl;

    return 0;
}
