#include <iostream>
#include <vector>
#include <stack>
#include <string>

std::string simplifyPath(const std::string &path)
{
    std::vector<std::string> names;
    std::string cur;
    for (char ch : path)
    {
        if (ch == '/')
        {
            names.push_back(std::move(cur));
            cur.clear();
        }
        else
        {
            cur += ch;
        }
    }
    names.emplace_back(std::move(cur));

    std::vector<std::string> stack;
    for (std::string &name : names)
    {
        if (name == "..")
        {
            if (!stack.empty())
            {
                stack.pop_back();
            }
        }
        else if (!name.empty() && name != ".")
        {
            stack.push_back(move(name));
        }
    }

    std::string result;
    if (stack.empty())
    {
        result = "/";
    }
    else
    {
        for (std::string &name : stack)
        {
            result += "/" + move(name);
        }
    }

    return result;
}

int main()
{
    /**
     * => /usr/local/mysql/data
     */
    std::cout << simplifyPath("/usr/local/mysql/config/../data") << std::endl;

    return 0;
}
