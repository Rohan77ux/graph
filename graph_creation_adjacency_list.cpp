#include <iostream>
#include <unordered_map>
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
    return 0;
}
