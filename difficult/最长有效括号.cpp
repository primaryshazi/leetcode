#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

int longestValidParentheses(const std::string &s)
{
    size_t result = 0;
    std::stack<int> stk;
    stk.push(-1);   // 推入-1作为起始点
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();

            /**
             * 若栈已空，则推入当前位置作为起始点
             * 若栈未空，则计算最大长度
             */
            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                result = std::max(result, i - stk.top());
            }
        }
    }

    return result;
}

int main()
{
    /**
     * => 2
     * => 4
     * => 6
     * => 6
     */
    std::cout << longestValidParentheses("()") << std::endl;
    std::cout << longestValidParentheses("()()") << std::endl;
    std::cout << longestValidParentheses("(()())") << std::endl;
    std::cout << longestValidParentheses("()(()(())") << std::endl;

    return 0;
}
