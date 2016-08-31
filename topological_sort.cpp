#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    void topological_sort_util(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int v);
    void add_edge(int v, int w);
    void topological_sort();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph:: topological_sort_util(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            topological_sort_util(*i,visited,Stack);
    }
    Stack.push(v);
}

void Graph:: topological_sort()
{
    stack<int> Stack;
    bool* visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
            topological_sort_util(i,visited,Stack);
    }
    while(Stack.empty() == false)
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    cout<<"\n";
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    cout << "Following is a Topological Sort of the given graph \n";
    g.topological_sort();
    return 0;
}
