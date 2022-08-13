#include <iostream>
#include <vector>
#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

std::vector<int> reversePrint(ListNode *head)
{
    std::stack<ListNode *> st;
    std::vector<int> result;

    while (head != nullptr)
    {
        st.push(head);
        head = head->next;
    }

    while (!st.empty())
    {
        result.emplace_back(st.top()->val);
        st.pop();
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
    ListNode *head = new ListNode(0);
    ListNode *next = head;
    for (int i = 1; i < 10; i++)
    {
        next->next = new ListNode(i);
        next = next->next;
    }

    /**
     * => { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }
     */
    std::cout << reversePrint(head) << std::endl;

    return 0;
}
