/*
Problem : Delete Node in a BST
Link : https://leetcode.com/problems/delete-node-in-a-bst/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return NULL;

		if (root->val < key) {
			root->right = deleteNode(root->right, key);
			return root;
		}

		if (root->val > key) {
			root->left = deleteNode(root->left, key);
			return root;
		}

		// No child - simply delete
		if (!root->left && !root->right) {
			root = NULL;
			delete(root);
			return NULL;
		}

		// Only one child - point that child to root's parent
		if (root->left && !root->right) {
			TreeNode* temp = root->left;
			delete(root);
			return temp;
		}
		else if (root->right && !root->left) {
			TreeNode* temp = root->right;
			delete(root);
			return temp;
		}
		// both children - replace root's data with inorder successor's data and delete latter node using recursion.
		else {
			TreeNode* ptr = root->right;
			while (ptr->left)
				ptr = ptr->left;
			root->val = ptr->val;
			root->right = deleteNode(root->right, ptr->val);
		}

		return root;
	}
};
/*
Approach: First search in BST as done.
When found, take 3 cases, if node has no child, one child and both children. 
*/