/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.*/
#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{

    int lSum = 0, rSum = 0, maxScore = 0;
    for (int i = 0; i < k; i++)
    {
        lSum += cardPoints[i];
        maxScore = lSum;
    }
    int rIndex = cardPoints.size() - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lSum -= cardPoints[i];
        lSum += cardPoints[rIndex--];
        maxScore = max(maxScore, lSum);
    }
    return maxScore;
}

int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int ans = maxScore(cardPoints, k);
    cout << ans;

    return 0;
}