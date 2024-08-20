#include <bits/stdc++.h>
using namespace std;

int findMaxNoOf1s(vector<int> arr)
{
    int maxOnes = 0;
    int currentOnes = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            currentOnes++;
            maxOnes = max(maxOnes, currentOnes);
        }
        else
        {
            currentOnes = 0;
        }
    }
    return maxOnes;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 1, 1, 1, 1, 0};
    int ans = findMaxNoOf1s(arr);
    cout << ans;
    return 0;
}
