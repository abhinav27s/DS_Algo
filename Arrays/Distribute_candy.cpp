/*
Problem : Distribute Candy
Link: https://www.interviewbit.com/problems/distribute-candy/
*/

int Solution::candy(vector<int>& ratings) {
    int i, n = ratings.size();
    int count = 0;
    vector<int> left, right;

    for (i = 0; i < n; i++) {
        left.push_back(1);
        right.push_back(1);
    }

    for (i = 1; i < n; i++)
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;

    for (i = n - 2; i >= 0; i--)
        if (ratings[i] > ratings[i + 1])
            right[i] = right[i + 1] + 1;

    for (i = 0; i < n; i++)
        count += max(left[i], right[i]);

    return count;
}
/*
Approach : If curr rating > previous rating => increase candy by 1 => store this from left to right for each element
           If curr rating > next rating => increase candy by  1 => => store this from right to left for each element

           Candy given to each is max of above 2 values for every i
*/