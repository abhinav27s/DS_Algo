/*
Problem:  All Nodes Distance K in Binary Tree
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 */
class Solution {
    vector<int> result;
    void printKDistDown(TreeNode* root, int k) {
        if (k < 0 || !root)
            return;
        printKDistDown(root->left, k - 1);
        if (k == 0)
            result.push_back(root->val);
        printKDistDown(root->right, k - 1);
    }
     
    int searchTarget(TreeNode* root, TreeNode* target, int K) {
        if (!root)
            return 0;
        if (root == target) {
            printKDistDown(root, K);
            return 1;
        }
        int l = searchTarget(root->left, target, K);
        int r = searchTarget(root->right, target, K);
        if (l > 0) {
            if (K - l == 0)
                result.push_back(root->val);
            printKDistDown(root->right, K - l - 1);
            return l + 1;
        }
        else if (r > 0) {
            if (K - r == 0)
                result.push_back(root->val);
            printKDistDown(root->left, K - r - 1);
            return r + 1;
        }

        return 0;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

        searchTarget(root, target, K);

        return result;
    }
};
/*
Approach : 2 sub-problems : 
    a. print all nodes downwards at dist k  - can be done easily
    b. print all nodes upwards and in other side sub-trees at dist k - done using recursion, which returns distance of target node(if present in subtree, else 0)
        from current node and thus remaining dist can be traversed on other side subtree of current node. 
        If remaining dist = 0, print current node and no need to traverse other side sub-tree.
*/