#include <iostream>
#include <vector>
using namespace std;

void adjmatrix(vector<pair<int, int>> v)
{
    int maxNode = 0;

    // Find maximum node
    for (auto i : v)
    {
        maxNode = max(maxNode, max(i.first, i.second));
    }

    vector<vector<int>> adj(maxNode + 1, vector<int>(maxNode + 1, 0));

    for (auto i : v)
    {
        int u = i.first;
        int x = i.second;

        adj[u][x] = 1;
        adj[x][u] = 1;
    }

    
    for (auto i : adj)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back({1, 3});
    v.push_back({3, 4});
    v.push_back({4, 5});

    adjmatrix(v);

    return 0;
}