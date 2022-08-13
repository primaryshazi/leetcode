#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void permutationCore(std::vector<std::string> &result, std::string s, size_t index)
{
    if (index == s.length() - 1)
    {
        result.emplace_back(s);
    }
    std::unordered_set<char> unorder;   // 记录该字符是否出现
    for (size_t i = index; i < s.length(); i++)
    {
        // 若该字符已经出现过则不再对该字符进行处理
        if (unorder.count(s[i]) > 0)
        {
            continue;
        }
        unorder.emplace(s[i]);
        std::swap(s[i], s[index]);
        permutationCore(result, s, index + 1);
        std::swap(s[i], s[index]);
    }
}

std::vector<std::string> permutation(std::string &s)
{
    std::vector<std::string> result;
    permutationCore(result, s, 0);
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
    std::string s = "HELLO";

    /**
     * => { HELLO, HELOL, HEOLL, HLELO, HLEOL, HLLEO, HLLOE, HLOLE, HLOEL, HOLLE, HOLEL, HOELL, EHLLO, EHLOL,
     *      EHOLL, ELHLO, ELHOL, ELLHO, ELLOH, ELOLH, ELOHL, EOLLH, EOLHL, EOHLL, LEHLO, LEHOL, LELHO, LELOH,
     *      LEOLH, LEOHL, LHELO, LHEOL, LHLEO, LHLOE, LHOLE, LHOEL, LLHEO, LLHOE, LLEHO, LLEOH, LLOEH, LLOHE,
     *      LOHLE, LOHEL, LOLHE, LOLEH, LOELH, LOEHL, OELLH, OELHL, OEHLL, OLELH, OLEHL, OLLEH, OLLHE, OLHLE,
     *      OLHEL, OHLLE, OHLEL, OHELL }
     *
     */
    std::cout << permutation(s) << std::endl;

    return 0;
}
