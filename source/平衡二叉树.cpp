#include <iostream>
#include <cmath>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        // 当左右子树深度差小于等于1且左右子树分别平衡时则为平衡二叉树
        return std::abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
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
    root1->right->right->right = new TreeNode(100);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(8);
    root2->right->right->right = new TreeNode(100);
    root2->right->right->right->right = new TreeNode(1000);

    /**
     * => 1
     * => 0
     */
    std::cout << isBalanced(root1) << std::endl;
    std::cout << isBalanced(root2) << std::endl;

    return 0;
}
