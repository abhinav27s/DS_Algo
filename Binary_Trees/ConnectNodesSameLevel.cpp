/*
Problem: Populating Next Right Pointers in Each Node
Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        root->next = NULL;
        Node* l1, * l2, * start_l2;
        l1 = root;
        l2 = start_l2 = NULL;
        while (l1) {

            if (l1->left) {
                if (start_l2 == NULL)
                    start_l2 = l2 = l1->left;
                else {
                    l2->next = l1->left;
                    l2 = l2->next;
                }
            }

            if (l1->right) {
                if (start_l2 == NULL)
                    start_l2 = l2 = l1->right;
                else {
                    l2->next = l1->right;
                    l2 = l2->next;
                }
            }
            l1 = l1->next;
            if (l1 == NULL) {
                if (l2)
                    l2->next = NULL;
                l1 = start_l2;
                start_l2 = l2 = NULL;
            }
        }
        return root;
    }
};
/*
Approach: Take 2 contigous levels simulataneously starting from root. - O(n) time, O(1) space.
First level is connected, make second level based on first level. 
*/