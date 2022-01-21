#include "Graph/LGraph.hpp"
#include <queue>
#include <climits>

#define INFINITY INT_MAX
void printPath(vector<int> par, int pos)
{
    if (pos > 0)
    {
        printPath(par, par[pos]);
        cout << pos << "->";
    }
}
void printShortestPath(int x, vector<int> par, vector<int> dist)
{
    if (par[x] == 0)
    {
        cout << -1 << endl;
        cout << "No solution" << endl;
    }
    else
    {
        cout << dist[x] << endl;
        printPath(par, par[x]);
        cout << x << endl;
    }
}
void printUnreachable(Graph *G, int x)
{
    bool allReachable = true;
    for (int i = 1; i <= x; i++)
    {
        if (G->getMark(i) == UNVISITED)
        {
            allReachable = false;
            cout << i << " ";
        }
    }
    if (allReachable)
    {
        cout << "All reachable";
    }
    cout << endl;
}
void bfs(Graph *G, int start, int n, int x, vector<int> &dist, vector<int> &par)
{
    resetMark(G);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    G->setMark(start, VISITED);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w = G->first(v); w < G->n(); w = G->next(v, w))
        {
            if (G->getMark(w) == UNVISITED)
            {
                G->setMark(w, VISITED);
                dist[w] = dist[v] + G->weight(v, w); // Increasing moves
                par[w] = v;                          // Setting parent square
                q.push(w);
            }
        }
    }
}
void solve(Graph *G, int n, int x)
{
    for (int v = 1; v <= x; v++)
    {
        if (G->getMark(v) == UNVISITED)
        {
            for (int w = v + 1; w <= v + n; w++)
            {
                G->setEdge(v, w, 1);
            }
        }
    }
    vector<int> dist(x + 1, INFINITY); // Minimum move to reach from source
    vector<int> par(x + 1, 0);         // Parent of a node in shortest path
    bfs(G, 1, n, x, dist, par);
    printShortestPath(x, par, dist);
    printUnreachable(G, x);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        Graph *G = new LGraph(x + 1);
        int l;
        cin >> l;
        for (int i = 0; i < l; i++)
        {
            int a, b;
            cin >> a >> b;
            G->setEdge(a, b, 0);
            G->setMark(a, VISITED);
        }
        int s;
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            int a, b;
            cin >> a >> b;
            G->setEdge(a, b, 0);
            G->setMark(a, VISITED);
        }
        solve(G, n, x);
    }
}