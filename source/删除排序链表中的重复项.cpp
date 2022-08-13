#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    ListNode *fastPrev = head;
    ListNode *fast = fastPrev->next;

    while (fast != nullptr)
    {
        if (fastPrev->val == fast->val)
        {
            fast = fast->next;
            delete fastPrev->next;
            fastPrev->next = fast;
        }
        else
        {
            fastPrev = fast;
            fast = fastPrev->next;
        }
    }

    return head;
}

void printList(ListNode *list)
{
    ListNode *node = list;

    while (nullptr != node)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *list = new ListNode(0);
    ListNode *node = nullptr;

    node = list;
    for (int i = 1; i < 10; i++)
    {
        node->next = new ListNode(i % 3 ? i : i + 1);
        node = node->next;
    }

    /**
     * => 0 1 2 4 4 5 7 7 8 10
     */
    printList(list);

    list = deleteDuplicates(list);

    /**
     * => 0 1 2 4 5 7 8 10
     */
    printList(list);

    return 0;
}
