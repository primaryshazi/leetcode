#include <iostream>
#include <stack>
#include <string>

bool isValidBracket(const std::string &str)
{
    std::stack<char> bracketStack;

    for (auto &ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            bracketStack.emplace(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (bracketStack.empty())
            {
                return false;
            }

            char top = bracketStack.top();

            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))
            {
                bracketStack.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return bracketStack.empty();
}

int main()
{
    std::string str1 = "()[]{}()[]()";
    std::string str2 = "{[({[()]})]}";
    std::string str3 = "{[({[(}]})]}";
    std::string str4 = "{{{{{{{{{{{{";

    /**
     * => 1
     * => 1
     * => 0
     * => 0
     */
    std::cout << isValidBracket(str1) << std::endl;
    std::cout << isValidBracket(str2) << std::endl;
    std::cout << isValidBracket(str3) << std::endl;
    std::cout << isValidBracket(str4) << std::endl;

    return 0;
}
