#include <iostream>
#include <functional>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if (nullptr == root)
    {
        return root;
    }

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

void printTree(TreeNode *root)
{
    std::function<void(TreeNode *)> inorder = [&inorder](TreeNode *node) {
        if (nullptr != node)
        {
            inorder(node->left);
            std::cout << node->val << " ";
            inorder(node->right);
        }
    };

    inorder(root);
    std::cout << std::endl;
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
     * => 2 3 4 5 6 7 8
     */
    printTree(root);

    root = invertTree(root);

    /**
     * => 8 7 6 5 4 3 2
     */
    printTree(root);

    return 0;
}
