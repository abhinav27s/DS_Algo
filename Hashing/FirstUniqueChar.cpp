/*
Problem: First Unique Character in a String
Link : https://leetcode.com/problems/first-unique-character-in-a-string/
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int i;
        int hashMap[26];

        for (i = 0; i < 26; i++)
            hashMap[i] = 0;

        for (i = 0; i < s.length(); i++)
            hashMap[s[i] - 97]++;

        for (i = 0; i < s.length(); i++)
            if (hashMap[s[i] - 97] == 1)
                return i;

        return -1;
    }
};