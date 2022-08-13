#include <iostream>
#include <utility>
#include <tuple>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::pair<ListNode *, ListNode *> reverseGroup(ListNode *head, ListNode *tail)
{
    ListNode *first = head;
    ListNode *last = tail->next;

    // 从first节点开始依次将节点插入到last之前
    while (last != tail)
    {
        ListNode *next = first->next;   // 记录下一个需要插入的节点
        first->next = last;
        last = first;
        first = next;
    }

    return { tail, head };
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *hair = new ListNode(0, head);
    ListNode *prev = hair;   // 记录反转组的前置节点

    while (head)
    {
        ListNode *tail = prev;

        // 找到需要反转组的最后一个节点
        for (int i = 0; i < k; ++i)
        {
            tail = tail->next;
            if (nullptr == tail)
            {
                return hair->next;
            }
        }

        ListNode *next = tail->next;    // 反转组后置节点
        std::tie(head, tail) = reverseGroup(head, tail);

        // 将反转之后的组与组的前置节点和后置节点衔接
        prev->next = head;
        tail->next = next;
        prev = tail;
        head = prev->next;
    }

    return hair->next;
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
    ListNode *next = list;
    for (int i = 1; i < 10; i++)
    {
        next->next = new ListNode(i);
        next = next->next;
    }

    list = reverseKGroup(list, 3);

    /**
     * => 2 1 0 5 4 3 8 7 6 9
     */
    printList(list);

    return 0;
}
