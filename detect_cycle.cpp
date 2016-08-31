#include <iostream>
#include <list>
#include <climits>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    bool isCycleUtil(int v,bool visited[],bool* rs);
public:
    Graph(int v);
    void add_edge(int v, int w);
    bool is_cycle();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::add_edge(int v,int w)
{
    adj[v].push_back(w);
}

bool Graph::isCycleUtil(int v, bool visited[], bool *rec_stack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        rec_stack[v] = true;
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end();i++)
        {
            if(!visited[*i] && isCycleUtil(*i,visited,rec_stack))
                return true;
            else if(rec_stack[*i])
                return true;
        }
    }
    rec_stack[v] = false;
    return false;
}

bool Graph::is_cycle()
{
    bool *visited = new bool[v];
    bool *rec_stack = new bool[v];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
        rec_stack[i] = false;
    }
    for(int i = 0; i < v; i++)
    {
        if(isCycleUtil(i,visited,rec_stack))
            return true;
    }
    return false;
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
    if(g.is_cycle())
        cout<<"Cycle found in graph \n";
    else
        cout<<"Cycle not found in graph \n";
    return 0;
}
