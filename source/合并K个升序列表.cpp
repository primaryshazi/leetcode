#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeSortList(ListNode *l1, ListNode *l2)
{
    ListNode head;

    ListNode *prev = &head;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            prev->next = l1;
            l1 = l1->next;
        }
        else
        {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 == nullptr ? l2 : l1;

    return head.next;
}

ListNode *merge(std::vector<ListNode *> &lists, int left, int right)
{
    if (left == right)
    {
        return lists[left];
    }
    if (left > right)
    {
        return nullptr;
    }

    int mid = left + ((right - left) >> 1);
    return mergeSortList(merge(lists, left, mid), merge(lists, mid + 1, right));
}

ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
    if (lists.empty())
    {
        return nullptr;
    }

    return merge(lists, 0, lists.size() - 1);
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
    ListNode *list1 = new ListNode(0);
    ListNode *list2 = new ListNode(0);
    ListNode *list3 = new ListNode(0);
    ListNode *node = nullptr;

    node = list1;
    for (int i = 1; i < 10; i += 2)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    node = list2;
    for (int i = 1; i < 10; i += 3)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    node = list3;
    for (int i = 1; i < 10; i += 5)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    std::vector<ListNode *> lists = { list1, list2, list3 };

    /**
     * => 0 0 0 1 1 1 3 4 5 6 7 7 9
     */
    printList(mergeKLists(lists));

    return 0;
}
