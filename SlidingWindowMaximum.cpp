#include <bits/stdc++.h>
using namespace std;

// sliding window
vector<int> maximumSumSubarray(int K, vector<int> &arr, int N)
{
    int i = 0, j = 0;

    vector<int> ans;
    list<int> li;

    while (j < N)
    {
        while (li.size() > 0 && li.back() < arr[j])
        {
            li.pop_back();
        }
        li.push_back(arr[j]);

        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            ans.push_back(li.front());
            if (li.front() == arr[i])
            {
                li.pop_front();
            }

            i++;
            j++;
        }
    }
    return ans;
}

int main()
{

    vector<int> Arr = {3, 2, -6, 1, 0};
    int n = Arr.size();
    int k = 3;
    vector<int> ans = maximumSumSubarray(k, Arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}