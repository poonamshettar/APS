#include <iostream>
using namespace std;

int main()
{
    int n, q, y1, x1, y2, x2;
    char c;
    cin >> n >> q; // Read the value of q
    int a[n][n];
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = dp[0][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            if (c == '*')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1] << endl;
    }
    return 0;
}
