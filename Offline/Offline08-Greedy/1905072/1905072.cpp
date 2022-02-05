/*
n plants
k friends
As gradually the cost of plants will increase. So, we will buy the cheapest plants later.
If we sort the array of plants in decreasing order,
then i-th (0<=i<k) friend will buy the {i+0*k,i+1*k,i+2*k.....} where 0<=i+j*k<n
So, i-th plant will be bought by (i%k)-th friend. With the price ((i/k)+1)*a[i].
We don't need to know which friend bougth which plant. We just need to know the buying price of each plant.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned int greedy(vector<int> cost, int nPlant, int nFriend)
{
    sort(cost.begin(), cost.end(), greater<int>());
    unsigned int totalCost = 0;
    for (int p = 0; p < nPlant; p++)
    {
        totalCost += ((p / nFriend) + 1) * cost[p]; // This plant is bougth by (p%nFriend)-th friend. And it is (p/nFriend)-th plant he has bought. So the price is ((p / nFriend) + 1) * cost[i]
    }
    return totalCost;
}
int main()
{
    int nPlant, nFriend;
    cin >> nPlant >> nFriend;
    vector<int> cost(nPlant);
    for (int &c : cost)
    {
        cin >> c;
    }
    cout << greedy(cost, nPlant, nFriend) << endl;
}
/*
Test cases:
Input:
3 3
2 5 6
Output:
13
Input:
3 2
2 5 6
Output:
15
Corner case:
Input:
100 2
1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000
Output:
2550000000
This will create overflow if we use 'int'[-2147483647,2147483647] for calculating output.
*/