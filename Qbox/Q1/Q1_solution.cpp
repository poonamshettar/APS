#include <bits/stdc++.h>
using namespace std;

void encode(string stock_t)
{
    for (int i = 0; i < stock_t.length(); i++)
    {
        cout << int(stock_t[i] - 55); // stock ticker identifier
    }
    cout << endl;
}

void maximum_price_gain(vector<int> &price_changes)
{
    int sum = 0;
    int maxi = INT_MIN;
    int si = 0, ei = 0, temp_start = 0;
    int maxi_ = INT_MIN, mini_ = INT_MAX;
    int max_, min_;

    for (int i = 0; i < price_changes.size(); i++)
    {
        sum += price_changes[i];

        if (sum > maxi)
        {
            maxi = sum;
            si = temp_start;
            ei = i;
            max_ = maxi_;
            min_ = mini_;
        }

        if (sum < 0)
        {
            sum = 0;
            temp_start = i + 1;
            maxi_ = INT_MIN;
            mini_ = INT_MAX;
        }

        maxi_ = max(maxi_, price_changes[i]);
        mini_ = min(mini_, price_changes[i]);
    }

    cout << maxi << endl; //"Maximum Price Gain: "
    cout << si << '\t';   //"Start Index: "
    cout << ei << endl;   //"End Index: "
    cout << max_ << endl; //"Maximum Value in Max Price gain period: "
    cout << min_ << endl; // "Minimum Value in Max Price gain period: "
}

int main()
{
    string stock_ticker;
    vector<int> price_changes(5);

    // cout << "Enter stock ticker: ";
    cin >> stock_ticker;

    // cout << "Enter 5 price changes: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> price_changes[i];
    }

    encode(stock_ticker);
    maximum_price_gain(price_changes);

    return 0;
}
