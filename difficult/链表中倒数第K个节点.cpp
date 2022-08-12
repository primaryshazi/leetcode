#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getKthFromEnd(ListNode *head, int k)
{
    if (k < 0)
    {
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    // 快指针先行K步
    while (fast != nullptr && k > 0)
    {
        fast = fast->next;
        k--;
    }
    if (k > 0)
    {
        return nullptr;
    }

    // 快慢指针并行，快指针到达尾部则满指针为目标节点
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *next = head;
    for (int i = 1; i < 5; i++)
    {
        next->next = new ListNode(i);
        next = next->next;
    }

    /**
     * => 0  -999
     * => 1  4
     * => 2  3
     * => 3  2
     * => 4  1
     * => 5  0
     * => 6  -999
     */
    for (int i = 0; i <= 6; i++)
    {
        ListNode *node = getKthFromEnd(head, i);
        std::cout << i << "  " << (node == nullptr ? -999 : node->val) << std::endl;
    }

    return 0;
}
