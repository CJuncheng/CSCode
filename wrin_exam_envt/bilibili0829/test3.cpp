/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    int findUnivaluePath(TreeNode* node, int& longest) {
        if (node == nullptr) {
            return 0;
        }
        int left = findUnivaluePath(node->left, longest);
        int right = findUnivaluePath(node->right, longest);

        int nLeft = 0, nRight = 0;

        if (node->left != nullptr && node->left->val == node->val) 
            nLeft = left + 1;
        if (node->right != nullptr && node->right->val == node->val)
            nRight = right + 1;

        longest = max(longest, nLeft + nRight);

        return max(nLeft, nRight);
    }

    int longestUnivaluePath(TreeNode* root) {
        // write code here
        if (root == nullptr) return 0;
        int longest = 0;
        findUnivaluePath(root, longest);
        return longest;
    }
};
