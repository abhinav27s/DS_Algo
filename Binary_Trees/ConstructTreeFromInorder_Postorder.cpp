/*
Problem : Construct Binary Tree from Inorder and Postorder Traversal
Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/
class Solution {
    int postIndex;
    TreeNode* searchInorder(int l, int h, vector<int> postorder, vector<int> inorder) {
        if (l > h || postIndex == 0)
            return NULL;
        postIndex--;
        for (int i = l; i <= h; i++)
            if (inorder[i] == postorder[postIndex]) {
                TreeNode* root = new TreeNode();
                root->val = inorder[i];
                root->right = searchInorder(i + 1, h, postorder, inorder);
                root->left = searchInorder(l, i - 1, postorder, inorder);
                return root;
            }
        return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        postIndex = postorder.size();
        return searchInorder(0, inorder.size() - 1, postorder, inorder);
    }
};