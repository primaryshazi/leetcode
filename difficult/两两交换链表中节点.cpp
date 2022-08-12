#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *onePtr = head;
    ListNode *twoPtr = head->next;

    while (twoPtr != nullptr)
    {
        std::swap(onePtr->val, twoPtr->val);

        /**
         * one指向two的下一个
         * two执行one的下一个
         */
        onePtr = twoPtr->next;
        if (nullptr == onePtr)
        {
            break;
        }
        twoPtr = onePtr->next;
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
    for (int i = 1; i < 5; i++)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    /**
     * => 1 0 3 2 4
     */
    printList(swapPairs(list));

    return 0;
}
