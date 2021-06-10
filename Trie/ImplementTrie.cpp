/*
Problem : Implement Trie (Prefix Tree)
Link : https://leetcode.com/problems/implement-trie-prefix-tree/
*/
struct Node{
    Node *children[26];
    bool isLeaf;
}*root;
class Trie {
    struct Node* makeNode(){
        Node* ptr = new Node();
        ptr->isLeaf=false;
        for(int i=0;i<26;i++)
            ptr->children[i]=NULL;
        return ptr;
    }
public:
    /** Initialize your data structure here. */
    Trie() {   
        root = makeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* ptr = root;
        int i=0;
        while(i<word.length()){
            if(!ptr->children[word[i]-97])
                ptr->children[word[i]-97] = makeNode();
            ptr=ptr->children[word[i]-97];
            i++;
        }
        ptr->isLeaf=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* ptr = root;
        int i=0;
        while(i<word.length())
        {
            if(!ptr->children[word[i]-97])
                return false;
            ptr=ptr->children[word[i]-97];
            i++;
        }
        if(ptr->isLeaf)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* ptr = root;
        int i=0;
        while(i<prefix.length())
        {
            if(!ptr->children[prefix[i]-97])
                return false;
            ptr=ptr->children[prefix[i]-97];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */