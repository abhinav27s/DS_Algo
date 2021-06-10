/*
Problem : Phone directory
Link : https://practice.geeksforgeeks.org/problems/phone-directory4628/
*/
#define MAX_CHILD 26
struct TrieNode{
    TrieNode *children[MAX_CHILD];
    bool isLeaf;
};
TrieNode* createNode(){
    TrieNode* p = new TrieNode();
    for(int i=0;i<MAX_CHILD;i++){
        p->children[i]=NULL;
        p->isLeaf=false;
    }
    return p;
}
void insertWord(TrieNode* root, string s){
    TrieNode* ptr = root;
    for(int i=0;i<s.length();i++){
        if(!ptr->children[s[i]-97])
            ptr->children[s[i]-97] = createNode();
        ptr = ptr->children[s[i]-97];
    }
    ptr->isLeaf = true;
}
void DFS(TrieNode* p, string s, vector<string> &result){
    if(!p)
        return;
    if(p->isLeaf)
        result.push_back(s);
    for(int i=0;i<MAX_CHILD;i++)
        if(p->children[i]){
            s.push_back(char(97+i));
            DFS(p->children[i],s,result);
            s.pop_back();
        }
}
vector<string> searchWord(TrieNode* root, string s){
    vector<string> result;
    TrieNode* ptr = root;
    for(int i=0;i<s.length();i++){
        if(!ptr->children[s[i]-97]){
            result.push_back("0");
            return result;
        }
        ptr = ptr->children[s[i]-97];
    }
    DFS(ptr,s,result);
    return result;
}
class Solution{
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        int i;
        TrieNode *root = createNode();
        for(i=0;i<n;i++)
            insertWord(root,contact[i]);
        vector<vector<string> > result;
        vector<string> temp;
        for(i=0;i<s.length();i++){
            temp = searchWord(root,s.substr(0,i+1));
            result.push_back(temp);
        }
        return result;
    }
};
/*
Approach : Trie is used. First, insert words in trie. Then for each prefix of query string, get all
possible words present in Trie using DFS.
*/