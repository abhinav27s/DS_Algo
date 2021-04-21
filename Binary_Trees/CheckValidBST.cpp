/*
Problem : Validate Binary Search Tree
Link : https://leetcode.com/problems/validate-binary-search-tree/
*/
class Solution {
    bool isValid(TreeNode* p, long long int l, long long int h)
    {
        if (p == NULL)
            return true;

        if (p->val<l || p->val>h)
            return false;

        if (p->val == INT_MIN)
        {
            if (p->left)
                return false;
            return isValid(p->right, p->val + 1, h);
        }
        if (p->val == INT_MAX)
        {
            if (p->right)
                return false;
            return isValid(p->left, l, p->val - 1);
        }

        return (isValid(p->left, l, p->val - 1) && isValid(p->right, p->val + 1, h));

    }
public:
    bool isValidBST(TreeNode* root) {

        if (!root)
            return true;

        return isValid(root, INT_MIN, INT_MAX);
    }
};