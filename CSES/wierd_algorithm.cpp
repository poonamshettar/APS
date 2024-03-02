#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << '\t';
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    }
    cout << n;
}