#ifndef __SNAKE_LADDER__
#define __SNAKE_LADDER__
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
// Some micros for better readability
#define VISITED true
#define UNVISITED false
#define INFINITY INT_MAX
#define NIL 0
// For error checking
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
class SnakeLadder
{
private:
    int nSquares;    // Total squares in the board
    int nFaces;      // Total faces in the die
    int *dist;       // Minimum move to reach from source
    int *parent;     // Parent of a node in shortest path
    bool *isVisited; // If a square is isVisited or not
    int *adj;        // i-th index will store the ending point of ladder/snake whose starting point is i. Since there can be only one ladder with starting point i, we can use 1D array for that. Note: adj[i] = i when the square doesn't contain any starting point of ladder/snake.
    queue<int> q;    // For BFS
    bool isPlayed;   // Flag to check if game is played.

public:
    // Default Constructor
    SnakeLadder()
    {
        isPlayed = false;
    }
    // n: Total squares in the board
    // k: Total faces in the die
    SnakeLadder(int n, int k)
    {
        setBoard(n, k);
        isPlayed = false;
    }
    // Destructor
    ~SnakeLadder()
    {
        delete[] dist, parent, isVisited, adj;
    }
    // Initializes the board
    // n: Total squares in the board
    // k: Total faces in the die
    void setBoard(int n, int k)
    {
        nSquares = n;
        nFaces = k;
        dist = new int[n + 1];
        parent = new int[n + 1];
        isVisited = new bool[n + 1];
        adj = new int[n + 1];
        // Initially connecting each node to itself
        for (int i = 0; i <= n; i++)
        {
            adj[i] = i;
        }
    }
    // Place a snake between u and v
    // u: Starting square of snake
    // v: Ending square of snake
    void setSnake(int u, int v)
    {
        Assert(u > v, "Not a snake");
        setEdge(u, v);
    }
    // Place a ladder between u and v
    // u: Starting square of ladder
    // v: Ending square of ladder
    void setLadder(int u, int v)
    {
        Assert(u < v, "Not a ladder");
        setEdge(u, v);
    }
    // Traverse the whole board to find the shortest path(BFS)
    // start: Starting point of the game (Default value:1)
    void play(int start);
    // Return: Least number of rolls needed to reach the destination
    int getMinRolls()
    {
        Assert(isPlayed, "Not played yet");
        return dist[nSquares];
    }
    // Return: The shortest path from source to destination
    vector<int> getShortestPath()
    {
        Assert(isPlayed, "Not played yet");
        vector<int> path;
        createPath(nSquares, path);
        return path;
    }
    // Return: Unreachable squares from the starting point
    vector<int> getUnreachable()
    {
        Assert(isPlayed, "Not played yet");
        vector<int> unreachable;
        for (int i = 1; i <= nSquares; i++)
        {
            if (isVisited[i] == UNVISITED)
            {
                unreachable.push_back(i);
            }
        }
        return unreachable;
    }

private:
    SnakeLadder(const SnakeLadder &board) {}    // Protect copy constructor
    void operator=(const SnakeLadder &board) {} // Protect assignment
    // Initializes BFS
    // source: The square from which BFS starts
    void init(int source)
    {
        for (int i = 1; i <= nSquares; i++)
        {
            if (i != source)
            {
                dist[i] = INFINITY;
                isVisited[i] = UNVISITED;
                parent[i] = NIL;
            }
        }
        dist[source] = 0;
        isVisited[source] = VISITED;
        parent[source] = NIL;
    }
    // Create shortest path from source to destination
    void createPath(int pos, vector<int> &path)
    {
        if (pos != NIL)
        {
            createPath(parent[pos], path);
            path.push_back(pos);
        }
    }
    // Connects u and v
    void setEdge(int u, int v)
    {
        adj[u] = v;
    }
};
/*
2 types of squares.
1. No starting point of snake/ladder
    - We can go to next n squares from this square (Using loop. Need to roll die.)
2. Starting point of snake/ladder
    - We can go to the end point of snake/ladder (Using 'adj' array. No need of rolling die.)
*/

/*
Traverse the whole board to find the shortest path(BFS)
start: Starting point of the game (Default value:1)
Note: While traversing the board we will face two types of squares.
    i) Square with no starting point of snake/ladder. 
        - We will continue our traversal from this square.
    ii) Square with starting point of snake/ladder. 
        - We will continue our traversal from the end point of the ladder. 
*/
void SnakeLadder::play(int start = 1)
{
    Assert(start > 0 && start <= nSquares, "Invalid starting position");
    init(start);
    q.push(start); // Starting traversal from the starting point
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // Moving to next squares by rolling die.
        for (int v = u + 1; v <= u + nFaces && v <= nSquares; v++)
        {
            if (isVisited[v] == UNVISITED)
            {                           // This square is not visited previously
                isVisited[v] = VISITED; // Visiting this square
                dist[v] = dist[u] + 1;  // Setting shortest distance from source
                parent[v] = u;          // Setting parent square
                // We are done with the basic steps. Now we have to determine if this square contains a ladder/snake or not.
                if (v == adj[v])
                {              // This square doesn't contain a ladder/snake
                    q.push(v); // Simply push it in the queue for further traversing.
                }
                else
                { // This square contains a ladder/snake
                    if (isVisited[adj[v]] == UNVISITED)
                    { // End point of the ladder is not visited
                        isVisited[adj[v]] = VISITED;
                        dist[adj[v]] = dist[v];
                        parent[adj[v]] = v;
                        q.push(adj[v]); // Pushing the end point(Not the starting point) in the queue for further traversal
                    }
                    else
                    { // Since end point of this ladder/snake is already visited we don't need to traverse further.
                    }
                }
            }
        }
    }
    isPlayed = true;
}
#endif
