#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void quick(ListNode *prev, ListNode *end)
{
    // 若待排序节点区间少于两个元素时，不予排序
    if (prev == end || prev->next == end || prev->next->next == end)
    {
        return;
    }

    ListNode *standard = prev->next;    // 记录比较的基准元素
    ListNode *start = prev->next;       // 开始比较的元素
    ListNode smallList;                 // 小于基准元素的链表
    ListNode *small = &smallList;

    while (start->next != end)
    {
        /**
         * 若待比较元素的值小于基准值，将该节点添加到smallList中，并将待比较元素指向下一个
         * 若待比较元素的值不小于基准值时，则将待比较节点步进
         */
        if (start->next->val < standard->val)
        {
            small->next = start->next;
            small = small->next;
            start->next = start->next->next;
        }
        else
        {
            start = start->next;
        }
    }

    // 将smallList添加到头部
    small->next = prev->next;
    prev->next = smallList.next;

    quick(prev, standard);
    quick(standard, end);
}

ListNode *sortListQuick(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode prev(0, head);
    quick(&prev, nullptr);
    return prev.next;
}

ListNode *merge(ListNode *one, ListNode *two)
{
    ListNode node(0);
    ListNode *ptr = &node;

    // 合并两条链表
    while (one != nullptr && two != nullptr)
    {
        auto &tmp = one->val < two->val ? one : two;
        ptr->next = tmp;
        ptr = ptr->next;
        tmp = tmp->next;
    }
    ptr->next = one != nullptr ? one : two;

    return node.next;
}

ListNode *sortListMerge(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    // 切分链表，用快慢指针切分，第一条链表从head开始，第二条链表从slow->next开始
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = nullptr;

    return merge(sortListMerge(head), sortListMerge(fast));
}

ListNode *sortList(ListNode *head)
{
    return sortListMerge(head);
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

    srand(0);
    node = list;
    for (int i = 1; i < 30; i++)
    {
        node->next = new ListNode(rand() % 100);
        node = node->next;
    }

    /**
     * => 0 38 19 38 37 55 97 65 85 50 12 53 0 42 81 37 21 45 85 97 80 76 91 55 6 57 23 81 40 25
     * => 0 0 6 12 19 21 23 25 37 37 38 38 40 42 45 50 53 55 55 57 65 76 80 81 81 85 85 91 97 97
     */
    printList(list);
    list = sortList(list);
    printList(list);

    return 0;
}
