/*
Problem : Boundary Traversal of binary tree 
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/
void inorder(Node* root, vector<int>& v) {
    if (!root)
        return;
    inorder(root->left, v);
    if (!root->left && !root->right)
        v.push_back(root->data);
    inorder(root->right, v);
}
vector <int> printBoundary(Node* root)
{
    vector<int> result, bottomB, leftB, rightB;
    if (!root)
        return result;

    leftB.push_back(root->data);
    Node* ptr = root->left;
    while (ptr) {
        leftB.push_back(ptr->data);
        if (ptr->left)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (root->left)
        leftB.pop_back();

    inorder(root, bottomB);

    ptr = root->right;
    while (ptr) {
        rightB.push_back(ptr->data);
        if (ptr->right)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    if (rightB.size() > 0) {
        rightB.pop_back();
        reverse(rightB.begin(), rightB.end());
    }

    int i = 0;
    while (i < leftB.size())
        result.push_back(leftB[i++]);
    i = 0;
    while (i < bottomB.size())
        result.push_back(bottomB[i++]);
    i = 0;
    while (i < rightB.size())
        result.push_back(rightB[i++]);
    return result;
}
/*
Approach: 3 parts - left boundary, leaves, right boundary.
Read clear definition of left and right boundary before approaching the problem.
Left & right boundaries can be obtained iteratively, and leaves can be obtained using simple inorder recursion.

Use cases to check : single node, node with only left subtree, node with only right subtree, node with both subtrees
*/