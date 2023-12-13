#include <bits/stdc++.h>
using namespace std;
// brute force
long maximumSumSubarray(int K, vector<int> &Arr, int N)
{

    long maxi = LONG_MIN;
    for (int i = 0; i <= N - K; i++)
    {
        long sum = 0;
        for (int j = i; j < i + K; j++)
        {
            sum = sum + Arr[j];
        }

        maxi = max(maxi, sum);
    }

    return maxi;
}

// sliding window
/*long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    int i = 0, j = 0;
    long sum = 0;
    long maxi = LONG_MIN;
    while (j < N)
    {
        sum = sum + Arr[j];
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            maxi = max(maxi, sum);
            sum = sum - Arr[i];
            i++;
            j++;
        }
    }
    return maxi;
}*/
int main()
{
    vector<int> Arr = {100, 200, 300, 400};
    int n = Arr.size();
    int k = 3;
    int ans = maximumSumSubarray(k, Arr, n);
    cout << ans;
    return 0;
}