/*Given a string s, find the length of the longest substring without repeating characters.*/
#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string s)
{
    unordered_map<char, int> mpp;
    int maxi = -1;
    int i = 0, j = 0;
    while (j < s.size())
    {
        mpp[s[j]]++;

        // if (mpp.size() > j - i + 1)
        // {
        //     j++;
        // }
        if (mpp.size() == j - i + 1)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (mpp.size() < j - i + 1)
        {
            while (mpp.size() < j - i + 1)
            {
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)
                {
                    mpp.erase(s[i]);
                }
                i++;
                if (mpp.size() == j - i + 1)
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
    string s = "bbbbb";

    int ans = longestKSubstr(s);
    cout << ans;
    return 0;
}