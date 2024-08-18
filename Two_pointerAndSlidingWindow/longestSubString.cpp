
#include <iostream>
using namespace std;
/*
int longestSubArrayWithSumLessThan14(int arr[], int n)
{
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum < 14)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}
*/

int longestSubArrayWithSumLessThan14(int arr[], int n)
{
    int maxLength = 0;
    int s = 0;
    int sum = 0;

    for (int e = 0; e < n; e++)
    {
        sum += arr[e];
        while (sum > 14)
        {
            sum -= arr[s];
            s++;
        }
        maxLength = max(maxLength, e - s + 1);
    }
    return maxLength;
}

int main()
{
    int arr[] = {2, 3, 4, 3, 6, 4};
    int size = sizeof(arr) / sizeof(int);

    int ans = longestSubArrayWithSumLessThan14(arr, size);
    cout << ans;
    return 0;
}
