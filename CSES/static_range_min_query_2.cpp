#include <iostream>
using namespace std;
int main()
{
    long long int n, q;
    cin >> n >> q;
    long long int a[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int dp[n][n];
    for (long long int i = 0; i < n; i++)
    {
        dp[i][i] = i;
    }
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = i + 1; j < n; j++)
        {
            dp[i][j] = (a[j] < a[dp[i][j - 1]]) ? j : dp[i][j - 1];
            // cout << dp[i][j] << '\t';
        }
        // cout << endl;
    }
    for (long long int k = 0; k < q; k++)
    {
        int c, d;
        cin >> c >> d;
        cout << a[dp[c - 1][d - 1]] << endl;
    }
}