#include <iostream>
#include <vector>
#include <list>
using namespace std;
class graph
{
public:
    vector<list<int>> gp;
    int numVertices;

public:
    graph(int num)
    {
        gp.resize(num);
    };
    void getEdges(int from, int to, bool flag);
    void print();
   
};

void graph::getEdges(int from, int to, bool flag)
{
    gp[from].push_back(to);
    if (flag)
    {
        gp[to].push_back(from);
    }
}

void graph::print()
{
    for (int i = 0; i < gp.size(); i++)
    {
        cout << "Vertices " << i << " : ";
        for (auto list : gp[i])
        {
            cout << list << ",";
        }
        cout << endl;
    }
}
 vector<int> dfs(int currnode , vector<bool> &visited , vector<list<int>> &gp){
    visited[currnode] = true;

    cout<<currnode<<"->";
    for(auto x:gp[currnode]){
        if(!visited[x]){
            dfs(x,visited , gp);
        }
    }
 }


int main()
{
    int vertices;
    cout << "Enter vertices::";
    cin >> vertices;
    cout << "Enter edges::";
    int edges;
    cin >> edges;
    graph gp(vertices);
    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        gp.getEdges(from, to, false);
    }
    gp.print();
    vector<bool> visited(vertices,false);
    dfs(0 , visited , gp.gp);

    return 0;
}
