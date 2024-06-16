#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Knuth-Morris-Pratt (KMP) algorithm for pattern searching
vector<int> computeLPS(const string &pattern)
{
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    vector<int> indices;
    int i = 0; // index for text[]
    int j = 0; // index for pattern[]

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            indices.push_back(i - j); // Found pattern at index i-j
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return indices;
}

string readTextFromFile(const string &filename)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }
    string line, content;

    while (getline(infile, line))
    {
        content += line + " ";
    }

    infile.close();
    return content;
}

vector<string> readPatternsFromFile(const string &filename)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return {};
    }

    string line;
    vector<string> patterns;

    while (getline(infile, line))
    {
        patterns.push_back(line);
    }

    infile.close();
    return patterns;
}

void findSentences(const string &content, const vector<string> &keywords, ofstream &outfile)
{
    for (const auto &keyword : keywords)
    {
        vector<int> indices = KMPSearch(content, keyword);
        if (indices.empty())
        {
            // outfile << "Keyword: " << keyword << endl;
            outfile << "NULL" << endl
                    << endl;
        }
        else
        {
            // outfile << "Keyword: " << keyword << endl;
            for (int index : indices)
            {
                int start = content.rfind('.', index);
                int end = content.find('.', index + keyword.size());
                if (start == string::npos)
                    start = -1;
                if (end == string::npos)
                    end = content.size();

                string sentence = content.substr(start + 1, end - start);
                outfile << sentence << endl;
                cout << sentence << endl;
            }
            outfile << endl;
        }
    }
}

int main()
{
    for (int i = 0; i < 13; i++)
    {
        string textFilename = "Q2_testcases\\testcase" + to_string(i) + ".txt";
        string patternFilename = "Q2_testcases\\testcase" + to_string(i) + "_pattern.txt";
        string outputFilename = "Q2_testcases\\Q2_output\\output" + to_string(i) + ".txt";

        string content = readTextFromFile(textFilename);
        if (content.empty())
            continue; // Skip if file reading failed

        vector<string> keywords = readPatternsFromFile(patternFilename);
        if (keywords.empty())
            continue; // Skip if file reading failed

        ofstream outfile(outputFilename);
        if (!outfile.is_open())
        {
            cerr << "Error opening file for writing: " << outputFilename << endl;
            continue;
        }

        findSentences(content, keywords, outfile);
        outfile.close();
    }

    return 0;
}
