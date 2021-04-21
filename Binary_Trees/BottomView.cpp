/*
Problem : Bottom View of Binary Tree 
Link : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
*/
vector <int> bottomView(Node* root)
{
    map<int, int> hashMap;
    queue<pair<int, Node*>> q;
    vector<int> result;

    if (!root)
        return result;

    q.push(make_pair(0, root));
    hashMap[0] = root->data;
    while (!q.empty()) {
        int width = q.size();
        while (width > 0) {
            pair<int, Node*> front = q.front();
            if (front.second->left) {
                q.push(make_pair(front.first - 1, front.second->left));
                hashMap[front.first - 1] = (front.second)->left->data;
            }
            if (front.second->right) {
                q.push(make_pair(front.first + 1, front.second->right));
                hashMap[front.first + 1] = (front.second)->right->data;
            }
            q.pop();
            width--;
        }
    }
    for (map<int, int>::iterator i = hashMap.begin(); i != hashMap.end(); i++)
        result.push_back(i->second);

    return result;
}
/*
Approach: Traverse using BFS/Level order and keep track of x-cordinate.
For each node, while pushing in queue, update latest value at that index (x-coordinate) in map. - O(n) time
*/