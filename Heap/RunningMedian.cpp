/*
Problem : Find Median from Data Stream
Link : https://leetcode.com/problems/find-median-from-data-stream/
*/
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        while (!maxHeap.empty())
            maxHeap.pop();
        while (!minHeap.empty())
            minHeap.pop();
    }

    void addNum(int num) {

        if (minHeap.empty()) {
            if (maxHeap.empty())
                maxHeap.push(num);
            else {
                if (num >= maxHeap.top())
                    minHeap.push(num);
                else {
                    int num2 = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(num2);
                    maxHeap.push(num);
                }
            }
            return;
        }

        if (num < maxHeap.top()) {
            maxHeap.push(num);
            if (maxHeap.size() - minHeap.size() > 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else if (num > minHeap.top()) {
            minHeap.push(num);
            if (minHeap.size() - maxHeap.size() > 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

        }
        else {
            if (maxHeap.size() > minHeap.size())
                minHeap.push(num);
            else
                maxHeap.push(num);
        }
    }

    double findMedian() {
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        if (minHeap.size() < maxHeap.size())
            return maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

/**
Approach : In a sorted array, median is eitther middle(in odd size) or avg of middle 2 elements(in even size)
So, create maxHeap to hold left half elements, and a minHeap to hold right half elements.
Roots of the heaps will give medians. 
 */