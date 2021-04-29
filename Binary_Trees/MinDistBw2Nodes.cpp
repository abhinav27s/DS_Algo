/*
Problem : Min distance between two given nodes of a Binary Tree
Link : https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
*/
int minDist;
int getDist(Node* root, int a, int b) {
    if (!root || minDist > 0)
        return 0;
    int l = getDist(root->left, a, b);
    int r = getDist(root->right, a, b);
    if (l > 0 && r > 0)
        minDist = l + r;
    if (root->data == a || root->data == b) {
        if (l > 0)
            minDist = l;
        else if (r > 0)
            minDist = r;
        return 1;
    }
    if (l > 0)
        return l + 1;
    if (r > 0)
        return r + 1;

    return 0;
}
int findDist(Node* root, int a, int b) {
    minDist = 0;
    getDist(root, a, b);
    return minDist;
}
/*
Approach : Similar to LCA. If node is LCA => then min dist = depth of left node + depth of right node
If node is not present in any subtree, return 0, else return updated depth of that node to parent.
*/