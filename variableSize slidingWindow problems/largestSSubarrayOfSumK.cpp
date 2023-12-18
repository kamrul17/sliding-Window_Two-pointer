/*Problem Description:
   // this code is not gonna work when input contain negative values;
Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is:
4 . */
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    //  int n = a.size();

    //     int len = 0;
    //     for (int i = 0; i < n; i++) {
    //         long long s = 0;
    //         for (int j = i; j < n; j++) {
    //             s += a[j];

    //             if (s == k)
    //                 len = max(len, j - i + 1);
    //         }
    //     }
    //     return len;
    // sliding window
    // int n = arr.size();
    // int i = 0, j = 0;
    // int maxi = INT8_MIN;
    // long long sum = 0;
    // while (j < n)
    // {
    //     sum = sum + arr[j];
    //     if (sum < k)
    //     {
    //         j++;
    //     }
    //     if (sum == k)
    //     {
    //         maxi = max(maxi, j - i + 1);
    //         j++;
    //     }
    //     if (sum > k)
    //     {

    //         while (sum > k)
    //         {

    //             sum = sum - arr[i];

    //             i++;
    //         }
    //         if (sum == k)
    //         {
    //             maxi = max(maxi, j - i + 1);
    //         }
    //         j++;
    //     }
    // }

    // return maxi;
    // two pointer
    int left = 0, right = 0;
    int N = arr.size();
    int maxLen = 0;
    long long sum = arr[0];
    while (right < N)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < N)
        {
            sum += arr[right];
        }
    }
    return maxLen;
}
int main()
{
    vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
    // vector<int> arr = {1, 2, 3, 1, 1, 1, 1};

    // vector<int> arr = {4, 1, 1, -2, 1, 5};

    int k = 5;
    int ans = longestSubarrayWithSumK(arr, k);
    cout << ans;
    return 0;
}