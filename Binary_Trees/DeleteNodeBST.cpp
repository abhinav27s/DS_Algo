/*
Problem : Delete Node in a BST
Link : https://leetcode.com/problems/delete-node-in-a-bst/
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* node = searchInBST(root, key, parent);

        if (!node->left && !node->right) {
            if (node == root)
                return NULL;
            if (parent->left == node)
                parent->left = NULL;
            else if (parent->right == node)
                parent->right = NULL;
            node = NULL;
            delete(node);
            return;
        }

        if ((node->left && !node->right) || (!node->left && node->right)) {
            if (parent->left == node) {
                if (node->left)
                    parent->left = node->left;
                else if (node->right)
                    parent->left = node->right;

            }
            else if (parent->right == node) {
                if (node->left)
                    parent->right = node->left;
                else if (node->right)
                    parent->right = node->right;
            }
        }
        else {
            TreeNode* ptr = node->right;
            parent = node;
            while (ptr->left) {
                ptr = ptr->left;
                parent = ptr;
            }
            node->data = ptr->data;

            if (ptr->right) {
                if (parent == node)
                    parent->right = ptr->right;
                else
                    parent->left = ptr->right;
            }
        }
        node->left = node->right = NULL;
        node = NULL;
        delete(node);
    }
};
/*
Approach: Take 3 cases, if node has no child, one child and both children. 
In one or both children, swap node with inorder successor data and delete latter.
*/