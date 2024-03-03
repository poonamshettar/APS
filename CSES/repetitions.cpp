#include <iostream>
#include <string>
using namespace std;
int main()
{
    string c;
    int count = 1, maxi = 1;
    getline(cin, c);
    for (int i = 0; i < c.length() - 1; i++)
    {
        if (c[i] == c[i + 1])
        {
            count++;
            maxi = max(count, maxi);
        }
        else
        {
            count = 1;
        }
    }
    cout << maxi;
}