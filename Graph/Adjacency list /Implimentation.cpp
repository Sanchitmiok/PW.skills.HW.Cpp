#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
    Graph(int numVertices);
    void addEdges(int from, int to);
    void print();

private:
    int numVertices;
    vector<vector<int>> List;
};
// initialisation of Graph
Graph::Graph(int numVertices) : numVertices(numVertices)
{
    List.resize(numVertices);
}
void Graph::addEdges(int from, int to)
{
    List[from].push_back(to);
    // List[to].push_back(from); // directional
    List[to].push_back(from); // undirectional

}
void Graph::print()
{
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertice " << i << " : ";
        for (int j=0 ; j<List[i].size() ; j++ )
        {
            if(j == List[i].size() -1){
              cout << List[i][j] ;
              break;  
            }
            cout << List[i][j] << " , ";
        }
        cout << endl;
    }
}

int main()
{

    cout << "How many vertices are their :: ";
    int num;
    cin >> num;
    Graph graph(num);
    cout<<"Eges";int Edges ; cin>>Edges;
    for(int i=0 ; i<Edges ; i++){
        int from , to;
        cin>>from>>to;
        graph.addEdges(from , to);
    }
    cout<<endl;
    graph.print();

    return 0;
}
