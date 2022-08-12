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

bool isSymmetric(TreeNode *l, TreeNode *r)
{
    if (l == nullptr && r == nullptr)
    {
        return true;
    }

    if (l == nullptr || r == nullptr)
    {
        return false;
    }

    if (l->val != r->val)
    {
        return false;
    }

    return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
}

bool isSymmetric(TreeNode *root)
{
    return isSymmetric(root, root);
}

int main()
{
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(2);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(8);

    /**
     * => 1
     * => 0
     */
    std::cout << isSymmetric(root1) << std::endl;
    std::cout << isSymmetric(root2) << std::endl;

    return 0;
}
