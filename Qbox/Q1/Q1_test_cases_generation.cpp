#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
using namespace std;

void generateRandomString(int length, ofstream &outFile)
{
    string str;
    for (int i = 0; i < length; ++i)
    {
        char randomChar = 'A' + rand() % 26;
        str += randomChar;
    }
    outFile << str << endl;
}

void generate_values(int length, ofstream &outFile)
{
    for (int i = 0; i < length; i++)
    {
        outFile << (rand() % 21) - 10 << '\t';
    }
    outFile << endl;
}

int main()
{
    int a[10] = {5, 10, 50, 100, 200, 300, 400, 400000, 5000000, 6000000};
    int b[10] = {5, 10, 15, 20, 25, 30, 35, 50, 100, 150};
    srand(time(0)); // Seed the random number generator once

    for (int i = 0; i < 10; i++)
    {
        string filename = "Q1_testcase" + to_string(i) + ".txt"; // Corrected filename generation
        ofstream MyFile(filename);
        if (MyFile.is_open())
        {
            generateRandomString(b[i], MyFile);
            generate_values(a[i], MyFile);
            MyFile.close();
            cout << "Data has been written to " << filename << endl;
        }
        else
        {
            cerr << "Unable to open " << filename << endl;
        }
    }
    return 0;
}
