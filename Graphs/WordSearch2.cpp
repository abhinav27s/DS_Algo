/*
Problem : Word Search II
Link : https://leetcode.com/problems/word-search-ii/
*/
struct Node{
    struct Node* child[26];
    bool isLeaf;
    string word;
}*root;

struct Node* makeNode(){
        Node* ptr = new Node();
        for(int i=0;i<26;i++)
            ptr->child[i]=NULL;
        ptr->isLeaf=false;
        ptr->word="";
        return ptr;
    }
void addWord(string word){
        int i=0;
        Node* ptr=root;
        while(i<word.length()){
            if(!ptr->child[word[i]-'a'])
                ptr->child[word[i]-'a'] = makeNode();
            ptr = ptr->child[word[i]-'a'];
            i++;
        }
        ptr->isLeaf=true;
        ptr->word=word;
    }
void matchWord(vector<vector<char>> &board, int x, int y, Node* parent, vector<string>& res){
    
    if(board[x][y]=='#' || !parent->child[board[x][y]-'a'])
        return;
    Node* ptr = parent->child[board[x][y]-'a'];
    if(ptr->isLeaf){
        res.push_back(ptr->word);
        ptr->isLeaf=false; // to not store duplicate words in result
    }
    
    char ch = board[x][y];
    board[x][y] = '#'; //visit
    if(x-1>=0 )
        matchWord(board,x-1,y,ptr,res);
    if(x+1<board.size())
        matchWord(board,x+1,y,ptr,res);
    if(y-1>=0)
        matchWord(board,x,y-1,ptr,res);
    if(y+1<board[0].size())
        matchWord(board,x,y+1,ptr,res);
    
    board[x][y]=ch; //unvisit
    
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        root = makeNode();
        int i,j;
        vector<string> res;
        for(i=0;i<words.size();i++)
            addWord(words[i]);
        for(i=0;i<board.size();i++)
            for(j=0;j<board[0].size();j++){
                if(words.size()==res.size())
                    return res;
                matchWord(board,i,j,root,res);
            }
        
        return res;
    }
};
/*
Approach : Store all words in trie first. Then for every cell in board, check if some word matches in trie, in DFS manner.
Implementation : start from root, and check for every cell, if matched, check for its next trie node and next neighbour cell, till word is formed.
Caution : To not store duplicate words in result, mark isLeaf as false after the word is found.
Seperate visitd array not needed to be taken. Can change board itself.
*/