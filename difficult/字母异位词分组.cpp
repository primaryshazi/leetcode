#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{
    std::unordered_map<std::string, std::vector<std::string>> record;
    std::vector<std::vector<std::string>> result;

    for (const auto &str : strs)
    {
        auto key = str;
        std::sort(key.begin(), key.end());
        record[key].emplace_back(str);
    }

    for (const auto &kv : record)
    {
        result.emplace_back(kv.second);
    }

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

    std::vector<std::string> group = { "eat", "tea", "tan", "ate", "nat", "bat" };

    /**
     * => { { bat }, { tan, nat }, { eat, tea, ate } }
     */
    std::cout << groupAnagrams(group) << std::endl;

    return 0;
}
