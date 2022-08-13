#include <iostream>
#include <stack>

class MinStack
{
public:
    MinStack() : min_(INT_MAX) {}

    ~MinStack() {}

    void push(int val)
    {
        min_ = std::min(val, min_);
        stk_.emplace(val);
        minStk_.emplace(min_);
    }

    void pop()
    {
        stk_.pop();
        minStk_.pop();
        min_ = minStk_.empty() ? INT_MAX : minStk_.top();
    }

    int top()
    {
        return stk_.top();
    }

    int getMin()
    {
        return min_;
    }

private:
    std::stack<int> stk_;
    std::stack<int> minStk_;
    int min_;
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
        std::cout << ms.top() << "  " << ms.getMin() << std::endl;
        ms.pop();
    }

    return 0;
}
