#include <iostream>
#include <vector>
using namespace std;
void binary(int x, int n)
{
    for (int j = 0; j < n; j++)
    {
        int rem = x % 2;
        cout << rem;
        x = x / 2;
    }
    cout << '\n';
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        int x = i ^ (i >> 1);
        binary(x, n);
    }
}