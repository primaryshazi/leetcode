#include <iostream>
#include <vector>
#include <string>

void generateParenthesisCore(size_t left, size_t right, size_t n, std::string &str, std::vector<std::string> &result)
{
    // 当括号均已填完时，则存储并返回
    if (str.size() == 2 * n)
    {
        result.emplace_back(str);
        return;
    }

    // 当左括号尚未填完时，可填入左括号
    if (left < n)
    {
        str.push_back('(');
        generateParenthesisCore(left + 1, right, n, str, result);
        str.pop_back();
    }
    // 当右括号小于左括号时，可填入右括号
    if (right < left)
    {
        str.push_back(')');
        generateParenthesisCore(left, right + 1, n, str, result);
        str.pop_back();
    }
}

std::vector<std::string> generateParenthesis(size_t n)
{
    if (n == 0)
    {
        return {};
    }

    std::string str;
    std::vector<std::string> result;

    generateParenthesisCore(0, 0, n, str, result);

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
     * => {  }
     * => { () }
     * => { (()), ()() }
     * => { ((())), (()()), (())(), ()(()), ()()() }
     * => { (((()))), ((()())), ((())()), ((()))(), (()(())), (()()()), (()())(), (())(()), (())()(), ()((())), ()(()()), ()(())(), ()()(()), ()()()() }
     */
    for (int i = 0; i < 5; i++)
    {
        std::cout << generateParenthesis(i) << std::endl;
    }

    return 0;
}
