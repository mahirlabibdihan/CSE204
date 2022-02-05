#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// There can be total 2^10-1 combinations = 1024
// But we are checking 10! combinations = 3628800
// So there are overlapping subproblems
// Suppose 2 sequence of visit:
// 1 -> 3 -> 5
// 3 -> 5 -> 1
// The min cost of all combinations after visiting 3 cities is same for the two

// set i-th bit
int visit(int mask, int idx)
{
    return mask | (1 << idx);
}

// is i-th bit is set
bool isVisited(int mask, int idx)
{
    return (mask & (1 << idx)) != 0;
}
// Cost to visit i-th city based on mask
int getCost(vector<vector<int>> cost, int nCity, int mask, int i)
{
    int totalCost = 0; // Cost based on previous visits
    for (int j = 0; j < nCity; j++)
    {
        if (isVisited(mask, j)) // j city is already visited or we are visiting it
        {
            totalCost += cost[i][j];
        }
    }
    return totalCost;
}
// City i is visited if i-th bit of mask is set.
// dp[i] will store the minimum cost to visit the cities represented by mask i.
// O((nCity^2)*(2^nCity))
int solve(vector<vector<int>> cost, int nCity)
{
    int nMask = 1 << nCity; // Total possible masks = 2^nCity
    vector<int> dp(nMask, INT_MAX);
    dp[0] = 0;
    for (int m = 0; m < nMask; m++) // Iterate all masks
    {
        for (int i = 0; i < nCity; i++)
        {
            if (!isVisited(m, i)) // City i is not visited
            {
                int mask = visit(m, i); // Visit i-th city
                dp[mask] = min(dp[mask], dp[m] + getCost(cost, nCity, mask, i));
            }
        }
    }
    return dp[nMask - 1];
}
int main()
{
    int nCity;
    cin >> nCity;
    vector<vector<int>> cost(10, vector<int>(10));
    for (int i = 0; i < nCity; i++)
    {
        for (int j = 0; j < nCity; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << solve(cost, nCity) << endl;
}
/*
What we will store at dp[i]?
Let, i = 21
21 = 0000010101
So, 21 means we have visited city 1,3 and 5.
So, in dp[21] we will store minimum cost to visit city 1,3,5 in any sequence.
There will be 3!=6 possible sequence to visit city 1,3,5. We will store the minimum cost among these 6 sequence in dp[21].
dp[1023] -> Answer
1023 = 1111111111

dp[1023] = 1<<10-1
*/