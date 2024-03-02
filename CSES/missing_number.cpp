#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long int n;
    cin >> n;
    long int sum1 = n * (n + 1) / 2;
    long int sum2 = 0;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        sum2 += a[i];
    }
    cout << sum1 - sum2;
}