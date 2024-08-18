
#include <bits/stdc++.h>
using namespace std;

int maxSubarrSumUsingKadaneAlgo(int arr[], int n)
{
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}
int maxSubarrLengtthUsingKadaneAlgo(int arr[], int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0, end = 0, temp = 0, maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            start = temp;
            end = i;
            maxLength = max(maxLength, end - start + 1);
        }

        if (sum < 0)
        {
            sum = 0;
            temp = i + 1;
        }
    }
    return maxLength;
}
vector<int> findMaxSubarrayUsingKadaneAlgo(int arr[], int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0, end = 0, temp = 0, maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            start = temp;
            end = i;
        }

        if (sum < 0)
        {
            sum = 0;
            temp = i + 1;
        }
    }
    vector<int> subarray;
    for (int i = start; i <= end; i++)
    {
        subarray.push_back(arr[i]);
    }
    return subarray;
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(int);
    // print sum
    int ans = maxSubarrSumUsingKadaneAlgo(arr, size);
    // print length
    int maxlength = maxSubarrLengtthUsingKadaneAlgo(arr, size);
    // // print subArray
    vector<int> res = findMaxSubarrayUsingKadaneAlgo(arr, size);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    // cout << ans;
    // cout << maxlength;
    return 0;
}