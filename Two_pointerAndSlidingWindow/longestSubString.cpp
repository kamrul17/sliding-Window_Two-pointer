#include <bits/stdc++.h>
using namespace std;
/*
int longestSubstrWithOutRepeatingChar(string str, int size)
{
    int maxlen = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        int hash[255] = {0};
        for (int j = i; j < size; j++)
        {
            if (hash[str[j]] == 1)
            {
                break;
            }
            else
            {
                maxlen = max(maxlen, j - i + 1);
                hash[str[j]] = 1;
            }
        }
    }
    return maxlen;
}
int longestSubstrWithOutRepeatingChar(string str, int size)
{
    int maxlen = INT_MIN;
    unordered_set<int> set;
    int l = 0, r = 0;
    while (r < size)
    {
        if (set.find(str[r]) != set.end())
        {
            while (l < r && set.find(str[r]) != set.end())
            {
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}*/
int longestSubstrWithOutRepeatingChar(string str, int size)
{
    int maxlen = INT_MIN;
    vector<int> hash(256, -1);
    int l = 0, r = 0;
    while (r < size)
    {
        if (hash[str[r]] != -1)
        {
            if (hash[str[r]] >= l)
            {
                l = hash[str[r]] + 1;
            }
        }
        hash[str[r]] = r;
        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}
int main()
{
    string str = "abcasdsgsa";
    int size = str.size();
    int len = longestSubstrWithOutRepeatingChar(str, size);
    cout << len;
    return 0;
}