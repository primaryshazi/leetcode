#include <iostream>
#include <stack>

class CQueue
{
public:
    CQueue() {}

    void appendTail(int value)
    {
        tail_.push(value);
    }

    int deleteHead()
    {
        // 当头栈为空时，将尾栈中的元素均置于出栈中
        if (head_.empty())
        {
            while (!tail_.empty())
            {
                head_.push(tail_.top());
                tail_.pop();
            }
        }

        // 无数据则直接返回
        if (head_.empty())
        {
            return -1;
        }

        int value = head_.top();
        head_.pop();

        return value;
    }

private:
    std::stack<int> tail_;
    std::stack<int> head_;
};

int main()
{
    CQueue que;

    for (int i = 0; i < 10; i++)
    {
        que.appendTail(i);
    }

    /**
     * => 0
     * => 1
     * => 2
     * => 3
     * => 4
     * => 5
     * => 6
     * => 7
     * => 8
     * => 9
     */
    for (int i = que.deleteHead(); i >= 0; i = que.deleteHead())
    {
        std::cout << i << std::endl;
    }

    return 0;
}
