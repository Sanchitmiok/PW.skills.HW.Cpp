#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
    Graph(int numVertices);
    void addEdges(int from, int to, int wt);
    void print();

private:
    int numVertices;
    vector<vector<pair<int, int>>> List;
};
// initialisation of Graph
Graph::Graph(int numVertices) : numVertices(numVertices)
{
    List.resize(numVertices);
}
void Graph::addEdges(int from, int to, int wt)
{
    List[from].push_back(make_pair(wt, to));
    List[to].push_back(make_pair(wt, from)); // undirectional
}
void Graph::print()
{
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertice " << i << " : ";

        for (auto x : List[i])
        {
            cout << "(" << x.first << " , " << x.second << ")"
                 << " , ";
        }

        cout << endl;
    }
}

int main()
{

    cout << "vertices -> ";
    int num;
    cin >> num;
    Graph graph(num);
    cout << "Eges -> ";
    int Edges;
    cin >> Edges;
    // cout << flush;
    cout << "Enter edges " << endl;
    for (int i = 0; i < Edges; i++)
    {
        int from, to, wt;
        cin >> from >> wt >> to;
        graph.addEdges(from, to, wt);
    }
    cout << endl;
    graph.print();

    return 0;
}
