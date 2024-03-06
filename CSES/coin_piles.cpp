#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        if ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}