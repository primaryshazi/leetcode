#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || k == 0)
    {
        return head;
    }

    // 获取链表长度求解移动步数
    int length = 1;
    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        ++length;
    }

    int step = length - k % length;
    if (step == 0 || step == length)
    {
        return head;
    }

    /**
     * => 找到第lenth-k个节点，即为移动后最后一个节点
     * => 然后将该节点之后的衔接到头节点之前
     */
    ListNode *prev = head;
    ListNode *next = head;
    while (step > 0)
    {
        prev = next;
        next = next->next;
        --step;
    }

    tail->next = head;
    head = prev->next;
    prev->next = nullptr;

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
    ListNode *head = new ListNode(0);
    ListNode *next = head;
    for (int i = 1; i < 10; i++)
    {
        next->next = new ListNode(i);
        next = next->next;
    }

    /**
     * => 0 1 2 3 4 5 6 7 8 9
     * => 5 6 7 8 9 0 1 2 3 4
     * => 3 4 5 6 7 8 9 0 1 2
     * => 3 4 5 6 7 8 9 0 1 2
     * => 0 1 2 3 4 5 6 7 8 9
     */
    head = rotateRight(head, 0);
    printList(head);
    head = rotateRight(head, 5);
    printList(head);
    head = rotateRight(head, 2);
    printList(head);
    head = rotateRight(head, 100);
    printList(head);
    head = rotateRight(head, 103);
    printList(head);

    return 0;
}
