/*
 Problem: Design Add and Search Words Data Structure
 Link : https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/
struct Node{
    Node *children[26];
    bool isLeaf;
}*root;
class WordDictionary {
    struct Node* makeNode(){
        Node* ptr = new Node();
        ptr->isLeaf=false;
        for(int i=0;i<26;i++)
            ptr->children[i]=NULL;
        return ptr;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = makeNode();
    }
    
    void addWord(string word) {
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
    bool searchInTrie(string word, int index, Node* ptr){
        if(index==word.length()){
            if(ptr->isLeaf)
                return true;
            return false;
        }
        for(int i=0;i<26;i++)
            if(ptr->children[i]){
                if(word[index]=='.' || word[index]-97==i)
                    if(searchInTrie(word,index+1,ptr->children[i]))
                        return true;
            }
        return false;
    }
    bool search(string word) {
        return searchInTrie(word,0,root);
    }
};

/**
Approach : Trie usage. For search query having '.', search for further characters, considering '.' to be any possible valid character.
 */