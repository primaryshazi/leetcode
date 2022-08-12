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
    if (nullptr == head)
    {
        return head;
    }

    ListNode *pre = new ListNode(0, head);

    ListNode *cur = pre;
    while (cur->next && cur->next->next)
    {
        if (cur->next->val == cur->next->next->val)
        {
            int x = cur->next->val;
            while (cur->next && cur->next->val == x)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }

    return pre->next;
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
        if (i % 3 == 0)
        {
            node->next = new ListNode(i);
        }
        else
        {
            node->next = new ListNode(i / 3 * 2);
        }
        node = node->next;
    }

    /**
     * => 0 0 0 3 2 2 6 4 4 9
     */
    printList(list);

    list = deleteDuplicates(list);

    /**
     * => 3 6 9
     */
    printList(list);

    return 0;
}
