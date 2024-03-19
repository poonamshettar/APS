#include <iostream>
using namespace std;

int main()
{
    long long int n, q, b, c, d;
    cin >> n;
    cin >> q;
    long long int *a = new long long int[n + 1];
    long long int *sum = new long long int[n + 1];

    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }

    sum[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> b >> c >> d;
        if (b == 1)
        {
            for (int j = c; j <= d; j++)
            {
                sum[j] += (d - a[c]);
                a[c] = d;
            }
        }
        else if (b == 2 && c <= d && d <= n)
        {
            cout << sum[d] - sum[c - 1] << endl;
        }
        else
        {
            cout << "Invalid query" << endl;
        }
    }

    delete[] a;
    delete[] sum;
    return 0;
}
