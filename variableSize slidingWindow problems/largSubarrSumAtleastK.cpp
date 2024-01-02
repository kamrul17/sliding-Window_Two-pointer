

#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k)
{
    long long int j = 0;
    long long int sum = 0;
    long long int last = 0;
    long long int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        sum = sum + a[i];

        if (i - j + 1 == k)
        {
            maxsum = max(maxsum, sum);
        }
        else if (i - j + 1 > k)
        {
            maxsum = max(maxsum, sum);
            last += a[j];
            j++;
            if (last < 0)
            {
                sum -= last;
                maxsum = max(maxsum, sum);
                last = 0;
            }
        }
    }
    return maxsum;
}

int main()
{
    long long int a[] = {1, 1, 1, 1, 1, 1};
    long long int n = sizeof(a) / sizeof(long long int);
    int k = 2;
    long long int len = maxSumWithK(a, n, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
