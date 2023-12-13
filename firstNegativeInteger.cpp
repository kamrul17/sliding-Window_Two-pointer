// First negative integer in every window of size k
#include <bits/stdc++.h>
using namespace std;
// brute force
/*vector<int> firstNegativeNum(int K, vector<int> &Arr, int N)
{

    vector<int> res;
    for (int i = 0; i <= N - K; i++)
    {
        bool foundNegative = false;
        for (int j = i; j < i + K; j++)
        {
            if (Arr[j] < 0)
            {
                res.push_back(Arr[j]);
                foundNegative = true;
                break;
            }
        }
        if (foundNegative == false)
        {
            res.push_back(0);
        }
    }

    return res;
}*/

// sliding window
vector<int> firstNegativeNum(int K, vector<int> &Arr, int N)
{
    int i = 0, j = 0;
    list<int> res;
    vector<int> ans;

    while (j < N)
    {
        if (Arr[j] < 0)
        {
            res.push_back(Arr[j]);
        }

        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            if (res.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(res.front());
                if (res.front() == Arr[i])
                {
                    res.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> Arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = Arr.size();
    int k = 3;
    vector<int> ans = firstNegativeNum(k, Arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}