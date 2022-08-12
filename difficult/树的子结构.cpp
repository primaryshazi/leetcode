#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSub(TreeNode *A, TreeNode *B)
{
    // 根节点相同则比较其左右节点是否相等

    /**
     * 当B为空时，则该节点直接判定相等
     * 当A未空时，此时B不为空，则B不与A相等
     */
    if (nullptr == B)
    {
        return true;
    }
    if (nullptr == A)
    {
        return false;
    }
    if (A->val != B->val)
    {
        return false;
    }

    return isSub(A->left, B->left) && isSub(A->right, B->right);
}


bool isSubStructure(TreeNode *A, TreeNode *B)
{
    // 当A或B为空时，不是任何树的子结构
    if (nullptr == A || nullptr == B)
    {
        return false;
    }

    return isSub(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
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

    TreeNode *t1 = new TreeNode(2);
    t1->left = new TreeNode(1);
    t1->right = new TreeNode(3);

    TreeNode *t2 = new TreeNode(7);
    t2->right = new TreeNode(8);

    /**
     * => 0
     * => 1
     */
    std::cout << isSubStructure(tree, t1) << std::endl;
    std::cout << isSubStructure(tree, t2) << std::endl;

    return 0;
}
