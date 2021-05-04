/*
Problem: Group Anagrams
Link: https://leetcode.com/problems/group-anagrams/
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hashMap;
        vector<vector<string>> result;
        int alphaMap[26] = { 0 };
        int i, j;
        for (i = 0; i < strs.size(); i++) {
            for (j = 0; j < strs[i].length(); j++)
                alphaMap[strs[i][j] - 97]++;
            string s = "";
            for (j = 0; j < 26; j++)
                if (alphaMap[j] > 0) {
                    while (alphaMap[j] > 0) {
                        s.push_back(char(97 + j));
                        alphaMap[j]--;
                    }
                }
            hashMap[s].push_back(strs[i]);
        }
        map<string, vector<string>>::iterator itr;
        for (itr = hashMap.begin(); itr != hashMap.end(); itr++)
            result.push_back(itr->second);

        return result;
    }
};
/*
Approach : For every word, make a key based on what characters used in the word and their frequency.
This key will be same for anagrams and hence, all related words should be stored as values of same key in a hash map.
At last, traverse this hash map and return the anagram groups.
*/