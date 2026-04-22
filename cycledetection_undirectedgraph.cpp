#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool bfsCycle(int src, vector<bool> &visit) {
        queue<pair<int,int>> q; 
        q.push({src, -1});
        visit[src] = true;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int parent = front.second;

            for (int nbr : adjList[node]) {
                if (!visit[nbr]) {
                    visit[nbr] = true;
                    q.push({nbr, node});
                }
                else if (nbr != parent) {
                    return true; 
                }
            }
        }
        return false;
    }

    bool isCycleBFS(int n) {
        vector<bool> visit(n, false);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                if (bfsCycle(i, visit)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); 

    if (g.isCycleBFS(4))
        cout << "Cycle detected (BFS)\n";
    else
        cout << "No cycle\n";

    return 0;
}