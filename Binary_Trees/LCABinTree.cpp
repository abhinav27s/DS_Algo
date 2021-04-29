/*
Problem : Lowest Common Ancestor of a Binary Tree
Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r)
            return root;
        if (root == p || root == q)
            return root;
        if (l)
            return l;
        if (r)
            return r;

        return NULL;
    }
};
/*
LCA is that node standing on which we get any of below cases-
1. Get value from left subtree and righ subtree
2. Get value from only left subtree and root value
3. Get value from only right subtree and root value
*/