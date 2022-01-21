#ifndef __L_GRAPH__
#define __L_GRAPH__
#include "Graph.hpp"
#include "Edge.hpp"
#include <list>
class LGraph : public Graph
{
private:
    vector<vector<Edge>> vertex; // List headers
    int numVertex, numEdge;      // Number of vertices, edges
    bool *mark;                  // Pointer to mark array
public:
    LGraph(int numVert)
    {
        init(numVert);
    }
    ~LGraph()
    {
        // Destructor
        delete[] mark; // Return dynamically allocated memory
        for (int i = 0; i < numVertex; i++)
        {
            delete vertex[i];
        }
        delete[] vertex;
    }
    void init(int n)
    {
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new bool[n]; // Initialize mark array
        for (i = 0; i < numVertex; i++)
        {
            mark[i] = UNVISITED;
        }
        // Create and initialize adjacency lists
        vertex = new List<Edge> *[numVertex];
        for (i = 0; i < numVertex; i++)
        {
            // vertex[i] = new DLList<Edge>();
            // vertex[i] = new SLList<Edge>();
            vertex[i] = new List<Edge>();
        }
    }
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges
    int first(int v)
    { // Return first neighbor of "v"
        if (vertex[v]->length() == 0)
            return numVertex; // No neighbor
        vertex[v]->moveToStart();
        Edge it = vertex[v]->getValue();
        return it.vertex();
    }
    // Get v’s next neighbor after w
    int next(int v, int w)
    {
        Edge it;
        if (isEdge(v, w))
        {
            if ((vertex[v]->currPos() + 1) < vertex[v]->length())
            {
                vertex[v]->next();
                it = vertex[v]->getValue();
                return it.vertex();
            }
        }
        return n(); // No neighbor
    }
    // Set edge (u, v) to "weight"
    void setEdge(int u, int v, int weight = 1)
    {
        Assert(weight >= 0, "Invalid Weight");
        if (isEdge(u, v))
        { // Edge already exists in graph
            // in isEdge() the curr position is set to where v is.
            // So, if we call remove(), it will delete v
            vertex[u]->remove();
        }
        else
        { // Keep neighbors sorted by vertex index: Optional
            // If we want we can just append the new edge
            // BUG: Not sorting properly
            numEdge++;
            for (vertex[u]->moveToStart(); vertex[u]->currPos() < vertex[u]->length(); vertex[u]->next())
            {
                Edge temp = vertex[u]->getValue();
                if (temp.vertex() > v)
                {
                    break;
                }
                if (vertex[u]->currPos() + 1 == vertex[u]->length())
                {
                    break;
                }
            }
        }
        vertex[u]->insert(Edge(v, weight));
    }
    void delEdge(int u, int v)
    { // Delete edge (i, j)
        if (isEdge(u, v))
        {
            vertex[u]->remove();
            numEdge--;
        }
    }
    // If (u,v) is an edge, this method sets curr position vertex[u], to the position of v
    bool isEdge(int u, int v)
    { // Is (u,v) an edge?
        for (vertex[u]->moveToStart(); vertex[u]->currPos() < vertex[u]->length(); vertex[u]->next())
        { // Check whole list
            Edge temp = vertex[u]->getValue();
            if (temp.vertex() == v)
            {
                return true;
            }
            if (vertex[u]->currPos() + 1 == vertex[u]->length())
            {
                break;
            }
        }
        return false;
    }
    int weight(int u, int v)
    { // Return weight of (u, v)
        Edge curr;
        if (isEdge(u, v))
        {
            curr = vertex[u]->getValue();
            return curr.weight();
        }
        else
        {
            return 0;
        }
    }
    bool getMark(int v) { return mark[v]; }
    void setMark(int v, bool val) { mark[v] = val; }
};
#endif