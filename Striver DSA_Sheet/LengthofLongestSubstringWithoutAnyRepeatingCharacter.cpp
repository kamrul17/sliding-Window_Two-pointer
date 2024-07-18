#include <bits/stdc++.h>
using namespace std;

// int getLongestSubstring(string s)
// {
//     int maxS = INT_MIN;
//     unordered_set<int> set;
//     cout << s.size();
//     if (s.size() == 0)
//     {
//         return 0;
//     }

//     for (int i = 0; i < s.length(); i++)
//     {

//         for (int j = i; j < s.length(); j++)
//         {
//             if (set.find(s[j]) != set.end())
//             {
//                 maxS = max(j - i, maxS);
//                 break;
//             }
//             set.insert(s[j]);
//         }
//     }
//     return maxS;
// }
int getLongestSubstring(string s)
{
    int maxS = 0; // Initialize to 0 to handle edge cases
    unordered_set<char> set;

    if (s.size() == 0)
    {
        return 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        set.clear();
        for (int j = i; j < s.length(); j++)
        {
            if (set.find(s[j]) != set.end())
            {
                break;
            }
            cout << "run" << endl;
            set.insert(s[j]);
            maxS = max(j - i + 1, maxS); // Update maxS for each new character added
        }
    }
    return maxS;
}

// optimise way using two pointer
int OptigetLongestSubstring(string s)
{
    int maxS = 0;
    unordered_set<char> set;
}
int main()
{
    string s = "ccc";
    // int ans = getLongestSubstring(s);
    int ans = OptigetLongestSubstring(s);
    cout << ans;
    return 0;
}