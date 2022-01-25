#include <iostream>
#include "SnakeLadder.hpp"
using namespace std;

// Takes input from the user and allocates memory for board.
void createBoard(SnakeLadder **board);
// Takes input from the user and places ladders according to that.
void placeLadders(SnakeLadder *board);
// Takes input from the user and places snakes according to that.
void placeSnakes(SnakeLadder *board);
// Deallocation
void destroyBoard(SnakeLadder *board);
// Prints least number rolls needed to reach the destination
void printMinRolls(SnakeLadder *board);
// Prints shortest path from source to destination
void printShortestPath(SnakeLadder *board);
// Prints unreachable square from the source
void printUnreachable(SnakeLadder *board);
// Solves each test case
void solve()
{
    SnakeLadder *board;
    createBoard(&board);      // Input
    placeLadders(board);      // Input
    placeSnakes(board);       // Input
    board->play();            // BFS
    printMinRolls(board);     // Output
    printShortestPath(board); // Output
    printUnreachable(board);  // Output
    destroyBoard(board);
}
// Main functions
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void printMinRolls(SnakeLadder *board)
{
    int minRolls = board->getMinRolls();
    if (minRolls == INFINITY)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minRolls << endl;
    }
}
void printShortestPath(SnakeLadder *board)
{
    vector<int> path = board->getShortestPath();
    if (path.size() < 2)
    {
        cout << "No solution";
    }
    else
    {
        int n = path.size();
        cout << path[0];
        for (int i = 1; i < n; i++)
        {
            cout << " -> " << path[i];
        }
    }
    cout << endl;
}
void printUnreachable(SnakeLadder *board)
{
    vector<int> unreachable = board->getUnreachable();
    if (unreachable.empty())
    {
        cout << "All reachable";
    }
    else
    {
        for (int i : unreachable)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void createBoard(SnakeLadder **board)
{
    int n, X;
    cin >> n >> X;
    *board = new SnakeLadder(X, n);
}
void placeLadders(SnakeLadder *board)
{
    int l;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int u, v;
        cin >> u >> v;
        board->setLadder(u, v);
    }
}
void placeSnakes(SnakeLadder *board)
{
    int s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int u, v;
        cin >> u >> v;
        board->setSnake(u, v);
    }
}
void destroyBoard(SnakeLadder *board)
{
    delete board;
}
/*
Corner case:
Input:
2 16
3
2 6
3 8
5 14
1
7 4
4
Output:
4
1 -> 2 -> 6 -> 7 -> 4 -> 5 -> 14 -> 16
All reachable
*/
/*

*/