#include <iostream>

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node *head = nullptr;   // 记录头节点
Node *pre = nullptr;    // 记录前置节点

void dfs(Node *cur)
{
    if (cur == nullptr)
    {
        return;
    }

    dfs(cur->left);

    if (pre != nullptr)
    {
        // 将当前节点与前置节点衔接
        cur->left = pre;
        pre->right = cur;
    }
    else
    {
        head = cur; // 头节点为最左边的最小节点
    }
    pre = cur;  // 将当前节点置为前置节点

    dfs(cur->right);
}

Node *treeToDoublyList(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    dfs(root);
    // 将最后一个节点与头节点衔接
    head->left = pre;
    pre->right = head;

    return head;
}

void printNode(Node *list)
{
    Node *node = list;

    while (nullptr != node)
    {
        std::cout << node->val << " ";
        node = node->right;
        if (node == list)
        {
            break;
        }
    }
    std::cout << std::endl;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    root->left->left->left = new Node(1);
    root->right->right->right = new Node(9);

    root = treeToDoublyList(root);

    /**
     * => 1 2 3 4 5 6 7 8 9
     */
    printNode(root);

    return 0;
}
