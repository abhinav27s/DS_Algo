/*
Problem: Flatten Binary Tree to Linked List (Preorder Fashion)
Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/
class Solution {
    TreeNode* prev;
    void treeToLL(TreeNode* root) {

        if (!root)
            return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = NULL;
        if (prev)
            prev->right = root;
        prev = root;
        treeToLL(l);
        treeToLL(r);

    }
public:
    void flatten(TreeNode* root) {
        prev = NULL;
        treeToLL(root);
    }
};
/*
Approach: Take a previous pointer and do preorder traversal recursively. - O(n) time & O(1) space except recursion.
Make links between previous and current node firstly as in preorder
*/