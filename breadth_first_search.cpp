#include <iostream>
#include <list>
#include <queue>

using namespace std;

class graph
{
    int v;
    list<int> *adj;
public:
    graph(int v);
    void add_edge(int v, int w);
    void bfs(int s);
};

graph::graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void graph::bfs(int s)
{
    bool* visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty())
    {
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout<<"\n";
}

int main()
{
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    cout<<"Breadth first traversal of given graph (starting from vertex 2)\n";
    g.bfs(2);
    return 0;
}