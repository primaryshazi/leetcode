#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    /**
     * 二者均为空则想等
     * 有一者为空则不相等
     * 值不等则不相等
     * 值等则比较分别比较期子节点
     */
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if (p == nullptr || q == nullptr)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(8);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(8);

    TreeNode *root3 = new TreeNode(5);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(7);
    root3->left->left = new TreeNode(2);
    root3->left->right = new TreeNode(4);
    root3->right->left = new TreeNode(6);

    /**
     * => 1
     * => 0
     */
    std::cout << isSameTree(root1, root2) << std::endl;
    std::cout << isSameTree(root1, root3) << std::endl;

    return 0;
}
