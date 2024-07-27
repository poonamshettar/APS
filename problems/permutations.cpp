#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void permute(int l, string x, int r)
{
    if (l == r)
    {
        ans.push_back(x);
        return;
    }
    for (int i = l; i < r; i++)
    {
        swap(x[i], x[l]);
        permute(l + 1, x, r);
        swap(x[i], x[l]);
    }
}
int main()
{
    string x = "abc";
    permute(0, x, x.size());
    for (const auto &s : ans)
    {
        cout << s << endl;
    }
    return 0;
}