#include <iostream>
#include <stack>

class MinStack
{
public:
    void push(int value)
    {
        min_ = std::min(value, min_);
        stack_.push(value);
        minStack_.push(min_);
    }

    void pop()
    {
        if (stack_.empty())
        {
            return;
        }

        stack_.pop();
        minStack_.pop();
        min_ = (minStack_.empty() ? INT_MAX : minStack_.top());
    }

    int top()
    {
        return stack_.top();
    }

    int min()
    {
        return min_;
    }

private:
    int min_ = INT_MAX;        // 当前最小值
    std::stack<int> stack_;    // 元素栈
    std::stack<int> minStack_; // 每个元素入栈时的最小元素
};

int main()
{
    const int N = 10;
    MinStack ms;

    for (int i = 0; i < N; i++)
    {
        ms.push(N - i);
    }

    /**
     * => 1  1
     * => 2  2
     * => 3  3
     * => 4  4
     * => 5  5
     * => 6  6
     * => 7  7
     * => 8  8
     * => 9  9
     * => 10  10
     */
    for (int i = 0; i < N; i++)
    {
        std::cout << ms.top() << "  " << ms.min() << std::endl;
        ms.pop();
    }

    return 0;
}
