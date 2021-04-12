/*
Problem : Rectangle Overlap
Link : https://leetcode.com/problems/rectangle-overlap/
*/
class Solution {
public:
    //O(1) time & space
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int a1 = rec1[0];
        int b1 = rec1[1];
        int c1 = rec1[2];
        int d1 = rec1[3];

        int a2 = rec2[0];
        int b2 = rec2[1];
        int c2 = rec2[2];
        int d2 = rec2[3];

        if (a2 >= c1 || c2 <= a1)
            return false;

        if (b2 >= d1 || d2 <= b1)
            return false;

        if (a1 == c1 || b1 == d1 || a2 == c2 || b2 == d2) // if any of 2 is a line
            return false;

        return true;
    }
};