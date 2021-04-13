/*
Problem: Element with all left side elements smaller and all right side elements greater in O(n) time
Link : https://practice.geeksforgeeks.org/problems/unsorted-array4925/1
*/
int findElement(int arr[], int n) {
    int leftMax[1000002], rightMin[1000002];
    int i;

    leftMax[0] = arr[0];
    for (i = 1; i < n; i++)
        leftMax[i] = max(arr[i], leftMax[i - 1]);

    rightMin[n - 1] = arr[n - 1];
    for (i = n - 2; i >= 0; i--)
        rightMin[i] = min(arr[i], rightMin[i + 1]);

    for (i = 1; i < n - 1; i++)
        if (arr[i] >= leftMax[i] && arr[i] <= rightMin[i])
            return arr[i];

    return -1;
}

/*
Approach : Store for each lement, max element in its left and min on its right. O(n) space
Return that element which is greater than max element on its left and smaller than min element
on its right.
*/