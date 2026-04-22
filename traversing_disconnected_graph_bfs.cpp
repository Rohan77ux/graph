#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

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
            adjList[v].push_back(u);
        }
    }

    void bfs(int src, vector<bool> &visit)
    {
        queue<int> q;
        q.push(src);
        visit[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            cout << frontNode << " ";

            for (int nbr : adjList[frontNode])
            {
                if (!visit[nbr])
                {
                    q.push(nbr);
                    visit[nbr] = true;
                }
            }
        }
    }

    void bfsDisconnected(int n)
    {
        vector<bool> visit(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                bfs(i, visit);
            }
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);

    // disconnected part
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);

    cout << "BFS Traversal (Disconnected Graph): ";
    g.bfsDisconnected(6);

    return 0;
}