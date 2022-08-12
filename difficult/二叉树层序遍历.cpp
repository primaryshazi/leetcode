#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    if (nullptr == root)
    {
        return {};
    }

    int current = 0;        // 当前需要打印的一层的节点储存栈
    int next = 1;           // 下一层需要打印的节点储存栈
    std::queue<TreeNode *> queNode[2];  // 分别记录当前需要打印的层和下一层
    std::vector<std::vector<int>> result;
    std::vector<int> vec;

    queNode[0].emplace(root);
    while (!queNode[0].empty() || !queNode[1].empty())
    {
        TreeNode *node = queNode[current].front();

        vec.emplace_back(node->val);

        // 父节点的子节点属于下一层
        if (nullptr != node->left)
        {
            queNode[next].push(node->left);
        }
        if (nullptr != node->right)
        {
            queNode[next].push(node->right);
        }

        queNode[current].pop();

        // 当前层打印完毕，则打印下一层
        if (queNode[current].empty())
        {
            result.emplace_back(vec);
            vec.clear();
            std::swap(current, next);
        }
    }

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

int main()
{
    /**
     *       5
     *   2       7
     * 1   4   6   8
     */
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(7);
    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);

    /**
     * => { { 5 }, { 2, 7 }, { 1, 4, 6, 8 } }
     */
    std::cout << levelOrder(tree) << std::endl;

    return 0;
}
