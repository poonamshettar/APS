#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string path;
    cin >> path;

    // Initialize the dp matrix with all values set to 0
    vector<vector<int>> dp(7, vector<int>(7, 0));

    // Base case: There's one way to reach the starting position
    dp[0][0] = 1;

    // Define the direction offsets
    int dx[] = {0, 0, -1, 1}; // U, D, L, R
    int dy[] = {-1, 1, 0, 0}; // U, D, L, R

    // Iterate through the given path
    for (char dir : path)
    {
        // Update the dp matrix based on the current direction
        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                if (dp[i][j] > 0)
                {
                    // Update the dp matrix for all possible directions
                    for (int k = 0; k < 4; ++k)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < 7 && nj >= 0 && nj < 7)
                        {
                            if (dir == '?' || dir == "UDLR"[k])
                            {
                                dp[ni][nj] += dp[i][j];
                                dp[ni][nj] %= 1000000007; // Apply modulo to avoid overflow
                            }
                        }
                    }
                }
            }
        }
    }

    // Print the number of paths to the destination
    cout << dp[6][0] << endl;

    return 0;
}
