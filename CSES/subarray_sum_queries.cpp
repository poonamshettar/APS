#include <iostream>
using namespace std;

void subarray(long long int ar[], long long int n)
{
    long long int sum = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    { // Loop from 0 to n-1
        sum += ar[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi << endl;
}

int main()
{
    long long int n, q, a, b;
    cin >> n >> q;
    long long int ar[n];
    for (int i = 0; i < n; i++)
    { // Loop from 0 to n-1
        cin >> ar[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        ar[a - 1] = b;   // Adjusting array index to 0-based indexing
        subarray(ar, n); // Call the subarray function after modifying array
    }
    return 0;
}
