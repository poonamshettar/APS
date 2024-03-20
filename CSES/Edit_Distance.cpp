#include <iostream>
#include <string>
using namespace std;
int minDistance(string word1, string word2)
{
    long long int l1 = word1.length();
    long long int l2 = word2.length();
    long long int dp[l1 + 1][l2 + 1];
    for (int i = 0; i < l1 + 1; i++)
    {
        // dp[0][i]=i;
        dp[i][0] = i;
    }
    for (int i = 0; i < l2 + 1; i++)
    {
        dp[0][i] = i;
        // dp[i][0]=i;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                long long int x = min(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i - 1][j - 1], x) + 1;
            }
            // cout << dp[i][j] << '\t';
        }
        // cout << '\n';
    }
    return dp[l1][l2];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    long long int x = minDistance(s1, s2);
    cout << x << endl;
}