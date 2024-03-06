#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int minDiff = INT32_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        long long int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum1 += a[j];
            }
            else
            {
                sum2 += a[j];
            }
        }
        minDiff = min(minDiff, abs(sum1 - sum2));
    }
    cout << minDiff << endl;

    return 0;
}
