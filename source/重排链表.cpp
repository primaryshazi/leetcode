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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;

    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *tmp1 = nullptr;
    ListNode *tmp2 = nullptr;

    while (l1 != nullptr && l2 != nullptr)
    {
        tmp1 = l1->next;
        tmp2 = l2->next;

        // l1，l2交替插入
        l1->next = l2;
        l1 = tmp1;
        l2->next = l1;
        l2 = tmp2;
    }
}

void reorderList(ListNode *head)
{
    if (nullptr == head)
    {
        return;
    }

    ListNode *mid = middleNode(head);
    ListNode *l1 = head;
    ListNode *l2 = mid->next;
    mid->next = nullptr;
    l2 = reverseList(l2);
    mergeList(l1, l2);
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
     * => 0 9 1 8 2 7 3 6 4 5
     */
    printList(list);
    reorderList(list);
    printList(list);

    return 0;
}
