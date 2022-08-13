#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    if (nullptr == head)
    {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
        node->next = new ListNode(i);
        node = node->next;
    }

    /**
     * => 0 1 2 3 4 5 6 7 8 9
     * => 5 6 7 8 9
     */
    printList(list);
    printList(middleNode(list));

    return 0;
}
