/*
Problem : Jumping Numbers
Link : https://practice.geeksforgeeks.org/problems/jumping-numbers3805
*/
class Solution {
  public:
    long long jumpingNums(long long X) {
        
        if(X/10==0)
            return X-1;
        long long max = 0;
        queue<long long> q;
        vector<bool> visited(X+5,false);
        for(int i=1;i<=9;i++){
            if(i>max)
                max=i;
            q.push(i);
            visited[i]=true;
        }
        
        
        while(!q.empty()){
            long long number = q.front();
            q.pop();
            long long lastDigit = number%10;
            if(lastDigit<9){
                long long newNo = number*10+lastDigit+1;
                if(newNo<=X && !visited[newNo]){
                    q.push(newNo);
                    if(newNo>max)
                        max=newNo;
                    visited[newNo]=true;
                }
            }
            if(lastDigit>0){
                long long newNo = number*10+lastDigit-1;
                if(newNo<=X && !visited[newNo]){
                    q.push(newNo);
                    if(newNo>max)
                        max=newNo;
                    visited[newNo]=true;
                }
            }
        }
        return max;
    }
};
/*
Approach : BFS. Add all 1-9 numbers initially, and then for each popped element, 
append 2 numbers(<=x) and track maximum -
first with digit lesser than last digit,
second with digit greater than last digit.
*/