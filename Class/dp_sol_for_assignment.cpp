#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// int count_set_bits(int p)
// {
//     char c[10];
//     int count = 0;
//     sprintf(c, "%d", p);
//     for (int x = 0; x < 3; x++)
//     {
//         if (c[x] == '1')
//         {
//             count++;
//         }
//     }
//     cout << "count=" << count << endl;
//     return count;
// }

// int count_set_bits(int n)
// {
//     int count = 0;
//     while (n)
//     {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }

int count_set_bits(int n)
{
    int count = 0;
    while (n)
    {
        int p = n % 2;
        if (p == 1)
        {
            count++;
        }
        n = n / 2;
    }
    return count;
}

int main()
{
    int n = 3;
    int dp[n];
    int z = pow(2, n);
    int cost[n][n] = {{3, 2, 7}, {5, 1, 3}, {2, 7, 2}};
    for (int i = 0; i < z; i++)
    {
        dp[i] = INT16_MAX;
    }
    dp[0] = 0;
    for (int mask = 0; mask < z; mask++)
    {
        int y = count_set_bits(mask);
        for (int j = 0; j < n; j++)
        {
            if (!(mask & (1 << j)))
            {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], cost[y][j] + dp[mask]);
            }
        }
    }
    cout << dp[z - 1];
}