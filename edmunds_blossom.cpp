# include <cstdio>
# include <vector>
# include <queue>

# define DEBUG 1

using namespace std;

int nVertices;

void readInput(vector< vector <int> >& graph) 
{
    int temp;
    scanf("%d",&nVertices);
    graph.clear();
    graph.resize(nVertices);

    for(int i =0 ; i < nVertices; i++) 
    {
        graph[i].clear();
        for(int j =0; j < nVertices; j++) 
        {
            scanf("%d", &temp);
            if (temp != 0) 
            {
                graph[i].push_back(j);
            }
        }
    }
    if (0 && DEBUG) 
    {
        for(int i =0; i < nVertices; i++) 
        {
            for(int j =0; j < graph[i].size(); j++) 
            {
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
    }
}

int main() 
{
    vector< vector <int> > graph;
    vector <int> mEdges ;
    freopen("input.txt","r", stdin);
    readInput(graph);
    mEdges .resize(nVertices, -1);
    bool foundAugmentingPath = false;

    do 
    {
        foundAugmentingPath = false;
        for(int i = 0; i < nVertices && !foundAugmentingPath; i ++) 
        {
            if (mEdges[i] == -1) 
            {
                vector <int> visited(nVertices, -1) ;
                queue <pair<int, int> > Q;
                visited[i] = -2;
                for (int j = 0; j < graph[i].size(); j++) 
                {
                    Q.push(pair<int, int>(i, graph[i][j]));
                }
                while(!Q.empty()) 
                {
                    pair<int, int> a = Q.front();
                    Q.pop();
                    visited[a.second] = a.first;
                    if(mEdges[a.second] == -1) 
                    { // reached an exposed vertex
                        // augmenting path found
                        int prev, cur = a.second, temp;
                        do {
                            prev = visited[cur];
                            temp = visited[prev];
                            mEdges [prev] = cur;
                            mEdges [cur] = prev;
                            cur = temp;
                        } while(temp != -2);
                        foundAugmentingPath = true;
                        if (DEBUG) 
                        {
                            printf("Found Augmenting path\n");
                            for(int i =0 ; i < nVertices; i ++) printf("%d ", mEdges[i]);
                            printf("----------\n");
                        }
                        break;
                    } 
                    else 
                    {
                        bool cameAlongAMatchedEdge = (mEdges[a.second] == a.first);
                        if (!cameAlongAMatchedEdge) 
                        {
                            Q.push(pair<int, int> (a.second, mEdges[a.second]));
                        } 
                        else 
                        {
                            for (int j = 0; j < graph[a.second].size(); j++) 
                            {
                                if(mEdges[a.second] != graph[a.second][j] && visited[graph[a.second][j]] == -1)
                                Q.push(pair<int, int>(a.second, graph[a.second][j]));
                            }
                        }
                    }
                }
            }
        }
    } 
    while (foundAugmentingPath);
}
