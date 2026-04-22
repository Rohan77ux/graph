#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, int direction)
    {
        if (direction == 1)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void dfs(int src, vector<bool> &visit)
    {
        visit[src] = true;
        cout << src << " ";

        for (int nbr : adjList[src])
        {
            if (!visit[nbr])
            {
                dfs(nbr, visit);
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);

    for (auto i : g.adjList)
    {
        cout << i.first << ": {  ";
        for (int neighbour : i.second)
        {
            cout << neighbour << ", ";
        }
        cout << "}" << endl;
    }
    int maxNode = 0;

    for (auto i : g.adjList)
    {
        maxNode = max(maxNode, i.first);

        for (int nbr : i.second)
        {
            maxNode = max(maxNode, nbr);
        }
    }

    vector<bool> visit(maxNode + 1, false);
    g.dfs(0, visit);

    return 0;
}
