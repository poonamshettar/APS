#include <iostream>
using namespace std;
int main()
{
    long long int n, q, b, c;
    cin >> n;
    cin >> q;
    long long int a[n + 1], sum[n + 1];
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
        cin >> b >> c;
        cout << sum[c] - sum[b] + a[b] << endl;
    }
}