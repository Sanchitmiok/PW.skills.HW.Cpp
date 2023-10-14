#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> initialiseGraph(int numOfvertices)
{
    return vector<vector<int>>(numOfvertices, vector<int>(numOfvertices, 0));
}
void getedges(vector<vector<int>> &graph, int i, int j)
{
    graph[i][j] = 1;
    graph[j][i] = 1;
}
void addVertices(vector<vector<int>> &graph)
{
    int vertices = graph.size();
    for (int i = 0; i < vertices; i++)
    {
        graph[i].push_back(0);
    }
    graph.push_back(vector<int>(vertices + 1, 0));
}
void dfs(vector<vector<int>> &graph, int startVertex, vector<bool> &visited)
{
    visited[startVertex] = true;
    // You can implement the DFS traversal logic here.
}

int main()
{
    vector<vector<int>> Graph = initialiseGraph(4);
    int howmanyEdge;
    cout << "How many edge are their :: ";
    cin >> howmanyEdge;
    for (int i = 0; i < howmanyEdge; i++)
    {
        int k, l;
        cin >> k >> l;
        getedges(Graph, k, l);
    }
    for (auto vec : Graph)
    {
        for (auto x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    addVertices(Graph);
    cout << endl;
    for (auto vec : Graph)
    {
        for (auto x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
