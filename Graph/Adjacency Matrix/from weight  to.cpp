#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> initialiseGraph(int numOfvertices)
{
    return vector<vector<pair<int,int>>>(numOfvertices, vector<pair<int,int>>(numOfvertices, make_pair(0,0)));
}
void getedges(vector<vector<pair<int,int>>> &graph, int i, int j,int wt)
{
    graph[i][j] = make_pair(wt,1);
    graph[j][i] = make_pair(wt,1);
}
void addVertices(vector<vector<pair<int,int>>> &graph)
{
    int vertices = graph.size();
    for (int i = 0; i < vertices; i++)
    {
        graph[i].push_back(make_pair(0,0));
    }
    graph.push_back(vector<pair<int,int>>(vertices + 1, make_pair(0,0)));
}
void dfs(vector<vector<pair<int,int>>> &graph, int startVertex, vector<bool> &visited)
{
    visited[startVertex] = true;
    // You can implement the DFS traversal logic here.
}

int main()
{
    int vertice;
    cout<<"Enter vertices : ";
    cin>>vertice;
    vector<vector<pair<int,int>>> Graph = initialiseGraph(vertice);
    int howmanyEdge;
    cout << "edges :: ";
    cin >> howmanyEdge;
    cout<<"Enter edges "<<endl;
    for (int i = 0; i < howmanyEdge; i++)
    {
        int k, l,wt;
        cin >> k >>wt>> l ;
        getedges(Graph, k, l,wt);
    }
    for (auto vec : Graph)
    {
        for (auto x : vec)
        {
            cout<<"("<<x.first<<","<<x.second<<"),";
        }
        cout << endl;
    }
    addVertices(Graph);
    cout << endl;
 for (auto vec : Graph)
    {
        for (auto x : vec)
        {
            cout<<"("<<x.first<<","<<x.second<<"),";
        }
        cout << endl;
    }

    return 0;
}
