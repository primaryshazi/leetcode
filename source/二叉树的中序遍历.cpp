#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversalByRecursion(TreeNode *root, std::vector<int> &vi)
{
    if (root != nullptr)
    {
        inorderTraversalByRecursion(root->left, vi);
        vi.emplace_back(root->val);
        inorderTraversalByRecursion(root->right, vi);
    }
}

void inorderTraversalByStack(TreeNode *root, std::vector<int> &vi)
{
    std::stack<TreeNode *> stk;

    while (root != nullptr || !stk.empty())
    {
        while (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        vi.emplace_back(root->val);
        root = root->right;
    }
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> vi;
    inorderTraversalByStack(root, vi);

    return vi;
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

    std::vector<int> vi = inorderTraversal(root);

    /**
     * => 2
     * => 3
     * => 4
     * => 5
     * => 6
     * => 7
     * => 8
     */
    for (auto i : vi)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
