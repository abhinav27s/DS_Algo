/*
Problem: Minimum Platforms for trains with given arrival and departure times
Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
*/

int minPlatform(int arrival[], int departure[], int n) {
    sort(arrival, arrival + n);     //sort arrival and departure times
    sort(departure, departure + n);

    int platform = 1, minPlatform = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arrival[i] < departure[j]) {
            platform++;     //platform added
            i++;
            if (platform > minPlatform)    //if platform value is greater, update minPlatform
                minPlatform = platform;
        }
        else {
            platform--;      //delete platform
            j++;
        }
    }
    return minPlatform;
}