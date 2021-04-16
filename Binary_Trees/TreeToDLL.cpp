/*
Problem: Binary Tree to DLL
Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
*/

class Solution
{
    Node* head, * prev;
    void treeToLL(Node* root) {

        if (!root)
            return;

        treeToLL(root->left);
        if (prev == NULL)
            head = root;
        else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        treeToLL(root->right);

    }
public:
    //Function to convert binary tree to doubly linked list and return it.
    // This function should return head to the DLL
    Node* bToDLL(Node* root)
    {
        head = prev = NULL;
        treeToLL(root);

        return head;
    }
};
/*
Approach: Take a previous pointer and do inorder traversal recursively. - O(n) time & O(1) space except recursion
Make links between previous and current node in between left and right recursive calls as in inorder
*/