#include <iostream>
#include <queue>

using namespace std;

#define v 4

bool is_bipartite(int arr[][v], int start)
{
    vector<int> color(v,-1);
    color[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < v; i++)
        {
            if(arr[u][i] && color[v] == -1)
            {
                color[i] = 1- color[u];
                q.push(i);
            }
            else if(arr[u][i] && color[i] == color[u])
                return false;
        }
    }
    return true;
}

int main()
{
    int graph[][v] = {{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
    if(is_bipartite(graph,0))
        cout<<"Given graph is Bipartite \n";
    else
        cout<<"Given graph is not Bipartite\n";
    return 0;
}
