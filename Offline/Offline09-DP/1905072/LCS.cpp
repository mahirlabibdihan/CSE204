#include <iostream>
using namespace std;
string backtrack(int dp[][51], string s1, int s1_size, int s2_size)
{
    string lcs(dp[s1_size][s2_size], '\0');
    int k = dp[s1_size][s2_size]; // Iterator for lcs
    int i = s1_size;              // Iterator for string 1
    int j = s2_size;              // Iterator for string 2
    // O(s1_size+s2_size)
    while (k > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1])
        {
            j--;
        }
        else
        {
            lcs[--k] = s1[i - 1];
            i--;
            j--;
        }
    }
    return lcs;
}
string LCS(string s1, string s2)
{
    int s1_size = s1.length();
    int s2_size = s2.length();
    int dp[51][51];
    // O(s1_size*s2_size)
    for (int i = 0; i <= s1_size; i++)
    {
        for (int j = 0; j <= s2_size; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // O(s1_size+s2_size)
    return backtrack(dp, s1, s1_size, s2_size);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string lcs = LCS(s1, s2);
    cout << lcs.length() << endl;
    cout << lcs << endl;
}