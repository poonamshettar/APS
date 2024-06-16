#include <bits/stdc++.h>
using namespace std;

void encode(string stock_t, ofstream &outFile)
{
    for (int i = 0; i < stock_t.length(); i++)
    {
        outFile << int(stock_t[i] - 55); // stock ticker identifier
    }
    outFile << endl;
}

void maximum_price_gain(vector<int> &price_changes, ofstream &outFile)
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

    outFile << maxi << endl; // "Maximum Price Gain: "
    outFile << si << '\t';   // "Start Index: "
    outFile << ei << endl;   // "End Index: "
    outFile << max_ << endl; // "Maximum Value in Max Price gain period: "
    outFile << min_ << endl; // "Minimum Value in Max Price gain period: "
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        string inputFilename = "Q1_testcase" + to_string(i) + ".txt";
        string outputFilename = "Q1_output" + to_string(i) + ".txt";

        ifstream inputFile(inputFilename);
        ofstream outputFile(outputFilename);

        if (inputFile.is_open() && outputFile.is_open())
        {
            string stock_ticker;
            vector<int> price_changes;
            int price;

            inputFile >> stock_ticker;

            while (inputFile >> price)
            {
                price_changes.push_back(price);
            }

            encode(stock_ticker, outputFile);
            maximum_price_gain(price_changes, outputFile);

            inputFile.close();
            outputFile.close();
            cout << "Processed " << inputFilename << " and wrote to " << outputFilename << endl;
        }
        else
        {
            cerr << "Unable to open " << inputFilename << " or " << outputFilename << endl;
        }
    }

    return 0;
}
