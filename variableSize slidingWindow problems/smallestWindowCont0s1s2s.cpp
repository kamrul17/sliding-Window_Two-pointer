/*Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.*/
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int smallestSubstringLength(string s)
{
    int n = s.length();
    int start = 0;
    int count[3] = {0};
    int minLen = INT8_MAX;
    for (int end = 0; end < n; end++)
    {
        count[s[end] - '0']++;
        while ((count[0] > 0) and (count[1] > 0) and (count[2] > 0))
        {
            minLen = min(minLen, end - start + 1);
            end++;
            count[s[start] - '0']--;
            start++;
        }
    }
    return (minLen == INT_MAX) ? -1 : minLen;
}

int main()
{
    string s = "210102";
    int result = smallestSubstringLength(s);

    cout << "Length of the smallest substring: " << result << endl;

    return 0;
}
