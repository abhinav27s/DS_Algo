/*
Problem : Pow(x, n)
Link : https://leetcode.com/problems/powx-n/
*/
class Solution {
    double power(double x, long long int n){
        if(x==1 || n==0)
            return 1;
        if(x==0)
            return 0;
        double root = power(x,n/2);
        if(n%2==0)
            return root*root;
        return root*root*x;
    }
public:
    double myPow(double x, int n) {
        long long int num = n;
        if(n<0)
            return 1/power(x,-num);
        return power(x,n);
    }
};
/*
Approach :
Use recursion, but take care of INT_MAX and INT_MIN values as they can be out of range 
Time complexity : log(n)
*/