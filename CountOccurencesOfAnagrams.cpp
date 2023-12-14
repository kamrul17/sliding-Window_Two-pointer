#include <bits/stdc++.h>
using namespace std;

int search(int k, string pat, int n, string txt)
{
    int i = 0, j = 0;
    unordered_map<char, int> mpp;
    int ans = 0;
    for (auto &x : pat)
    {
        mpp[x]++;
    }
    int count = mpp.size();
    // cout << count;
    while (j < n)
    {

        if (mpp.find(txt[j]) != mpp.end())
        {
            mpp[txt[j]]--;

            if (mpp[txt[j]] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans++;
            }

            if (mpp.find(txt[i]) != mpp.end())
            {
                mpp[txt[i]]++;

                if (mpp[txt[i]] == 1)
                {
                    count++;
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
    string text = "aabaabaa";
    string pat = "aaba";
    int n = text.size();
    int k = pat.size();

    int ans = search(k, pat, n, text);
    cout << ans;
    return 0;
}
