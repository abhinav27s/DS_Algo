/*
Problem : count all distinct nodes that are distance k from a leaf node
Link : https://practice.geeksforgeeks.org/problems/node-at-distance/1#
*/

int countN = 0;
void printKDistanceUtility(Node* root, int k, bool visited[], int ar[], int top) {

    if (!root)
        return;

    ar[top] = root->data;
    visited[top] = false;

    if (!root->left && !root->right) {
        if (top - k >= 0 && visited[top - k] == false) {
            visited[top - k] = true;
            countN++;
        }
    }
    printKDistanceUtility(root->left, k, visited, ar, top + 1);
    printKDistanceUtility(root->right, k, visited, ar, top + 1);

}
//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* node, int k)
{
    bool visited[100002] = { false };
    int ar[100002];
    int top = 0;
    countN = 0;
    printKDistanceUtility(node, k, visited, ar, top);

    return countN;
}
/*
Approach : Traverse using recursion and store ancestors in array parallely.
On visiting leaf node, print node which k elements back from current position.
To print only unique nodes, take visited array of position/level, and not the element's value. - Space - O(Height of tree)
*/