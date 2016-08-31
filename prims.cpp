#include <iostream>
#include <vector>
#include <climits>
#include <list>

#define v 5

using namespace std;

int min_key(vector<int> key, vector<bool> mst_set)
{
    int min = INT_MIN;
    int min_idx;
    for(int i = 0; i < v; i++)
    {
        if(mst_set[i] == false && key[i] < min)
        {
            min = key[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int print_mst(vector<int> parent, vector< vector<int>> graph)
{
    cout<<"Edge weight\n";
    for(int i = 1; i < v; i++)
    {
        cout<<parent[i]<<" - "<<graph[i][parent[i]]<<"\n";
    }
}

void prims_mst(vector< vector<int>> graph)
{
    vector<int> key(v,INT_MIN);
    vector<bool> mst_set(v,false);
    vector<int> parent(v);
    key[0] = 0;
    parent[0] = -1;
    for(int j = 0; j < v-1; j++)
    {
        int u = min_key(key,mst_set);
        mst_set[u] = true;
        for(int i = 0; i < v; i++)
        {
            if(graph[u][i] && mst_set[i] == false && graph[u][i] < key[i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    print_mst(parent,graph);
}

int main()
{
    vector< vector<int>> graph {{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
    prims_mst(graph);
    return 0;
}
