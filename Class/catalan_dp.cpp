#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> dp(10, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[i - j - 1] * dp[j];
        }
    }
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << '\t';
    }
}