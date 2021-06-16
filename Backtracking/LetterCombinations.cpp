/*
Problem : Letter Combinations of a Phone Number
Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution {
    void getCombinations(int index, string s, string digits, map<int,string> hashMap, vector<string> &result){
        if(index==digits.length()){
            result.push_back(s);
            return;
        }
        int x = digits[index]-'0';
        for(int i=0;i<hashMap[x].length();i++)
            getCombinations(index+1,s+hashMap[x][i],digits,hashMap,result);
        
    }
public:
    vector<string> letterCombinations(string digits) {
        map<int,string> hashMap;
        hashMap[2]="abc";
        hashMap[3]="def";
        hashMap[4]="ghi";
        hashMap[5]="jkl";
        hashMap[6]="mno";
        hashMap[7]="pqrs";
        hashMap[8]="tuv";
        hashMap[9]="wxyz";
        vector<string> result;
        string s="";
        if(digits.length()>0)
            getCombinations(0,s,digits,hashMap,result);
        return result;
    }
};
/*
Approach : Simple backtracking
*/