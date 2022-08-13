#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(const std::vector<int> &nums, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    // 每次取中间值作为父节点
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums.at(mid));

    root->left = buildTree(nums, left, mid - 1);
    root->right = buildTree(nums, mid + 1, right);

    return root;
}

TreeNode *sortedArrayToBST(const std::vector<int> &nums)
{
    int length = static_cast<int>(nums.size());

    return buildTree(nums, 0, length - 1);
}

void printTree(TreeNode *root)
{
    if (nullptr != root)
    {
        printTree(root->left);
        std::cout << root->val << std::endl;
        printTree(root->right);
    }
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    /**
     * => 1
     * => 2
     * => 3
     * => 4
     * => 5
     * => 6
     * => 7
     * => 8
     * => 9
     */
    printTree(sortedArrayToBST(nums));

    return 0;
}
