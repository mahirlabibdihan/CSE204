/*
    While traversing the board if we are on square 'playerPos'. Then we will face two situation,
        1. If there is a ladder/snake we have to go up/down using that.
            i) There can be maximum one ladder/snake in a square.
            ii) So we can use an array to store if there is a ladder/snake in a square. Lets say 'adj'
            iii) If there is a ladder/snake from 'a' to 'b', we will set adj[a] = b
            iv) If we are on the 'a' square, then using the array value we can go to 'b' square.
        2. We can go to {playerPos+1,playerPos+2, ... , playerPos+n} squares by rolling the dies.
            i) If we are on 'playerPos' square, we will iterate from playerPos+1 to playerPos+n .
    So, we have to handle the two situation differently.
*/
#ifndef __SNAKE_LADDER__
#define __SNAKE_LADDER__
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
#define VISITED true
#define UNVISITED false
#define INFINITY INT_MAX
#define NIL 0
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
class SnakeLadder
{
private:
    int nSquares, nFaces;
    int *dist;   // Minimum move to reach from source
    int *parent; // Parent of a node in shortest path
    int playerPos;
    vector<int> *adj;
    priority_queue<pair<int, int>> q;
    bool isPlayed;

public:
    SnakeLadder(int n, int k)
    {
        nSquares = n;
        nFaces = k;
        dist = new int[n + 1];
        parent = new int[n + 1];
        adj = new vector<int>[n + 1];
        isPlayed = false;
    }
    ~SnakeLadder()
    {
        delete[] dist, parent, adj;
    }
    void setSnake(int u, int v)
    {
        Assert(u > v, "Not a snake");
        setEdge(u, v);
    }
    void setLadder(int u, int v)
    {
        Assert(u < v, "Not a ladder");
        setEdge(u, v);
    }
    void play(int start = 1)
    {
        Assert(start > 0 && start <= nSquares, "Invalid starting position");
        playerPos = start;
        init(playerPos);

        while (!q.empty())
        {
            playerPos = q.top().second;
            q.pop();
            if (!adj[playerPos].empty()) // There is ladder/snake in this square
            {
                for (int nextPos : adj[playerPos])
                {
                    if (isLadder(nextPos))
                    {
                        moveUp(nextPos);
                    }
                    else if (isSnake(nextPos))
                    {
                        slideDown(nextPos);
                    }
                }
            }
            else
            {
                roll();
            }
        }
        isPlayed = true;
    }
    void printMinRolls()
    {
        Assert(isPlayed, "Not played yet");
        int X = nSquares;
        if (parent[X] == NIL)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[X] << endl;
        }
    }
    void printShortestPath()
    {
        Assert(isPlayed, "Not played yet");
        int X = nSquares;
        if (parent[X] == NIL)
        {
            cout << "No solution" << endl;
        }
        else
        {
            printPath(parent[X]);
            cout << X << endl;
        }
    }
    void printUnreachable()
    {
        Assert(isPlayed, "Not played yet");
        bool isAllReachable = true;
        for (int i = 1; i <= nSquares; i++)
        {
            if (dist[i] == INFINITY)
            {
                isAllReachable = false;
                cout << i << " ";
            }
        }
        if (isAllReachable)
        {
            cout << "All reachable";
        }
        cout << endl;
    }

private:
    SnakeLadder(const SnakeLadder &board) {}
    void operator=(const SnakeLadder &board) {}
    void init(int source)
    {
        for (int i = 1; i <= nSquares; i++)
        {
            if (i != source)
            {
                dist[i] = INFINITY;
                parent[i] = NIL;
            }
        }
        dist[source] = 0;
        parent[source] = NIL;
        q.push(make_pair(-dist[source], source));
    }
    void printPath(int pos)
    {
        if (pos > 0)
        {
            printPath(parent[pos]);
            cout << pos << "->";
        }
    }
    void setEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void roll()
    {
        // Traversing next n squares
        for (int v = playerPos + 1; v <= playerPos + nFaces && v <= nSquares; v++)
        {
            if (dist[v] > dist[playerPos] + 1)
            {
                dist[v] = dist[playerPos] + 1; // Increasing moves
                parent[v] = playerPos;         // Setting parent square
                q.push(make_pair(-dist[v], v));
            }
        }
    }
    void goUpOrDown(int v)
    {
        if (dist[v] > dist[playerPos] + 0)
        {
            dist[v] = dist[playerPos] + 0; // Since we don't need any move go from on square to another through ladder/snake. Number of moves won't increase here.
            parent[v] = playerPos;
            q.push(make_pair(-dist[v], v));
        }
    }
    void moveUp(int v)
    {
        goUpOrDown(v);
    }
    void slideDown(int v)
    {
        goUpOrDown(v);
    }
    bool isSnake(int v)
    {
        return playerPos > v;
    }
    bool isLadder(int v)
    {
        return playerPos < v;
    }
};
#endif