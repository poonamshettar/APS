#include <iostream>
using namespace std;
int main()
{
    int n;
    long int c = 0;
    cin >> n;
    long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        while (a[i - 1] > a[i])
        {
            if (a[i] < a[i - 1])
            {
                c += (a[i - 1] - a[i]);
                a[i] = a[i - 1]; // Ensure non-decreasing order
            }
        }
    }
    cout << c;
}