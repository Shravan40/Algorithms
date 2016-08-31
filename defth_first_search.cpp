#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    void dfs_util(int v,bool visited[]);
public:
    Graph(int v);
    void add_edge(int v,int w);
    void dfs();
};

Graph::Graph(int v)
{
    this->v=v;
    adj = new list<int>[v];
}

void Graph:: add_edge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::dfs_util(int v,bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!visited[*i])
            dfs_util(*i,visited);
    }
}

void Graph::dfs()
{
    bool* visited = new bool[v];
    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
            dfs_util(i,visited);
    }
    cout<<"\n";
}

int main()
{
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    cout<<"Following is the Depth First Traversal (starting from vetex 0)\n";
    g.dfs();
    return 0;

}
