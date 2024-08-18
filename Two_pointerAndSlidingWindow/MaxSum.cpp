
#include <iostream>
using namespace std;

int twoPointer(int arr[], int n, int k)
{
    int s = 0, e = 0;
    int windowSum = 0;
    int maxSum = 0;

    // Initialize the first window
    while (e < k)
    {
        windowSum += arr[e++];
    }

    // Slide the window across the array
    while (e < n)
    {
        windowSum += arr[e++] - arr[s++];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    int arr[] = {2, 3, 4, 0, 6};
    int size = sizeof(arr) / sizeof(int);

    int k = 3;
    int ans = twoPointer(arr, size, k);
    cout << ans; // Output should be 10 (4 + 0 + 6)
    return 0;
}