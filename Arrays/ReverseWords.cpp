/*
Problem : Reverse Words in a String
Link : https://leetcode.com/problems/reverse-words-in-a-string/
*/
class Solution {
public:
    string reverseWords(string s) {
        string result = "", temp;
        int i, j;
        i = j = 0;
        while (i < s.length() && j < s.length()) {
            temp = "";
            while (j < s.length()) {
                if (s[j] == ' ')
                    break;
                temp.push_back(s[j]);
                j++;
            }
            if (temp.length() > 0) {
                reverse(temp.begin(), temp.end());
                result += temp + " ";
            }
            i = j + 1;
            j = i;
        }
        result.pop_back();
        reverse(result.begin(), result.end());

        return result;
    }
};
/*
Approach : From left to right, reverse every word, not spaces, and keep storing in a string. At last reverse whole string.
Can use stack/stl reverse() method to reverse words.
Take care of test cases containing multiple spaces in between, or at extremes.
*/