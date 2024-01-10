#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int longSubarrWthSumDivByK(vector<int> &arr, int n, int K)
{

    unordered_map<int, int> mpp;
    int prefixSum = 0;
    int maxLength = 0;
    int remainder = 0;
    mpp[0] = -1;

    for (int i = 0; i < n; ++i)
    {
        prefixSum = prefixSum + arr[i];
        remainder = prefixSum % K;
        if (remainder < 0)
        {
            remainder += K;
        }

        if (mpp.find(remainder) != mpp.end())
        {
            maxLength = max(maxLength, i - mpp[remainder]);
        }

        if (mpp.find(remainder) == mpp.end())
        {
            mpp[remainder] = i;
        }
    }

    return maxLength;
}
int main()
{
    // Example usage:
    vector<int> arr = {4, 5, 0, -2, -3, 1};
    int n = arr.size();
    int K = 5;
    int result = longSubarrWthSumDivByK(arr, n, K);
    cout << "Length of the longest subarray with sum divisible by K: " << result << endl;

    return 0;
}