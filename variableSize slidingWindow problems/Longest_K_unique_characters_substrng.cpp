#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k)
{
    unordered_map<char, int> mpp;
    int maxi = -1;
    int i = 0, j = 0;
    while (j < s.size())
    {
        mpp[s[j]]++;

        if (mpp.size() < k)
        {
            j++;
        }
        else if (mpp.size() == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (mpp.size() > k)
        {
            while (mpp.size() > k)
            {
                mpp[s[i]]--;

                if (mpp[s[i]] == 0)
                {
                    mpp.erase(s[i]);
                }
                i++;
                if (mpp.size() == k)
                {
                    maxi = max(maxi, j - i + 1);
                }
            }
            j++;
        }
    }
    return maxi;
}
int main()
{
    string s = "aabacbebebe";
    int k = 3;
    int ans = longestKSubstr(s, k);
    cout << ans;
    return 0;
}