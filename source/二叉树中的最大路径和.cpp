#include <iostream>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPath(TreeNode *root, int &maxValue)
{
    if (nullptr == root)
    {
        return 0;
    }

    int left = std::max(0, maxPath(root->left, maxValue));
    int right = std::max(0, maxPath(root->right, maxValue));
    maxValue = std::max(left + right + root->val, maxValue);

    return std::max(left, right) + root->val;
}

int maxPathSum(TreeNode *root)
{
    int maxValue = INT_MIN;
    maxPath(root, maxValue);

    return maxValue;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    /**
     * => 27
     */
    std::cout << maxPathSum(root) << std::endl;

    return 0;
}
