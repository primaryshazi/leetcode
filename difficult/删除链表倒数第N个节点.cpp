#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (nullptr == head)
    {
        return head;
    }

    ListNode *prev = head;
    ListNode *slow = head;
    ListNode *fast = head;

    // 快指针先行n步
    while (fast != nullptr && n > 0)
    {
        fast = fast->next;
        --n;
    }

    // n超范围则直接返回
    if (n > 0)
    {
        return head;
    }

    // 快慢指针同时前进，直到快指针达到尾部
    while (fast != nullptr)
    {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }

    /**
     * 若慢指针与前指针相同，则说明删除的是第一个节点则直接将头指针指向第二个节点
     * 否则，直接越过慢节点
     */
    if (prev == slow)
    {
        head = slow->next;
    }
    else
    {
        prev->next = slow->next;
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
        node->next = new ListNode(i);
        node = node->next;
    }

    /**
     * => 0 1 2 3 4 6 7 8 9
     */
    printList(removeNthFromEnd(list, 5));

    return 0;
}
