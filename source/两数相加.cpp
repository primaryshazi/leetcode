#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;      // 进位
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    while (l1 != nullptr || l2 != nullptr)
    {
        int x = l1 != nullptr ? l1->val : 0;
        int y = l2 != nullptr ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;

        if (l1 != nullptr)
        {
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            l2 = l2->next;
        }

        if (head == nullptr)
        {
            head = new ListNode(sum % 10);
            tail = head;
        }
        else
        {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
    }

    // 当最后仍需进位时，需添加一个节点
    if (carry > 0)
    {
        tail->next = new ListNode(carry);
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
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    l1->next->next->next = new ListNode(7);

    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    l2->next->next->next = new ListNode(8);

    ListNode *l3 = addTwoNumbers(l1, l2);

    /**
     * => 3 7 1 6 1
     */
    printList(l3);

    return 0;
}
