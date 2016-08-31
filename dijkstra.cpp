# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <algorithm>
# include <vector>
# include <list>
# include <queue>

using namespace std;
const int INFTY = 10000000;
const int MAXV = 100;

int AdjMat[MAXV+2][MAXV+2];
int Pos[MAXV+2][2];
int MinDist [MAXV+2];

int dijkstraN2(int V,int s) {
    int Dist[MAXV+2];

    int i,fix, curV;
    int min, minpos;

    for (i=0; i<V; i++) {
        MinDist [i] = INFTY;
        Dist [i] = INFTY;
    }

    Dist [s] = 0;
    for(fix=0; fix < V; fix ++) {
        min = INFTY;
        for(curV=0; curV < V; curV++) {
            if(min > Dist[curV]) {
                min = Dist[curV];
                minpos = curV;
            }
        }
        MinDist [minpos] = min;
        Dist[minpos] = INFTY;

        for(curV=0; curV < V; curV++) {
            if (Dist[curV] > AdjMat[minpos][curV] + min && MinDist[curV] == INFTY) {
                Dist[curV] =  AdjMat[minpos][curV] + min;
            }
        }
    }

    return 0;
}

struct Edge {
    int EndV;
    int Cost;
};
struct compare {
    bool operator()(Edge e1, Edge e2) {
        return e1. Cost > e2. Cost;
    }
};

vector < list<Edge> > AdjList;
vector <int> MinCost;

int NVertices, NEdges;
int StartV, EndV;

void Dijkstra() {
    priority_queue< Edge, vector<Edge>, compare> EQueue;

    MinCost. resize(NVertices);
    for (int v=0; v < NVertices; v++){
        MinCost[v] = INFTY;
        cout << "MinCost " << v << " : " << MinCost[v] << endl;
    }
    Edge temp;
    temp . Cost = 0;
    temp . EndV = StartV;

    EQueue . push (temp);
    while(! EQueue. empty()) {
        temp = EQueue. top();
        EQueue . pop();

        int Ver = temp . EndV;
        if (MinCost [Ver] == INFTY) {
            MinCost [Ver] = temp. Cost;
            list <Edge> :: iterator it;
            for (it = AdjList[Ver].begin(); it != AdjList[Ver].end(); ++it) {
                if (MinCost[(*it).EndV] == INFTY) {
                    Edge e;
                    e. EndV = (*it).EndV;
                    e. Cost = (*it).Cost + MinCost[Ver];
                    EQueue. push(e);
                }
            }
        }
    }
}


int main(){
    NVertices = 6; Edge e;
    AdjList.resize(NVertices);

    e.Cost = 7; e.EndV = 1;
    AdjList[0].push_back(e);
    e.Cost = 9; e.EndV = 2;
    AdjList[0].push_back(e);
    e.Cost = 14; e.EndV = 5;
    AdjList[0].push_back(e);

    e.Cost = 7; e.EndV = 0;
    AdjList[1].push_back(e);
    e.Cost = 10; e.EndV = 2;
    AdjList[1].push_back(e);
    e.Cost = 15; e.EndV = 3;
    AdjList[1].push_back(e);

    e.Cost = 9; e.EndV = 0;
    AdjList[2].push_back(e);
    e.Cost = 10; e.EndV = 1;
    AdjList[2].push_back(e);
    e.Cost = 11; e.EndV = 3;
    AdjList[2].push_back(e);
    e.Cost = 2; e.EndV = 5;
    AdjList[2].push_back(e);

    e.Cost = 6; e.EndV = 4;
    AdjList[3].push_back(e);
    e.Cost = 11; e.EndV = 2;
    AdjList[3].push_back(e);
    e.Cost = 15; e.EndV = 1;
    AdjList[3].push_back(e);

    e.Cost = 9; e.EndV = 5;
    AdjList[4].push_back(e);
    e.Cost = 06; e.EndV = 3;
    AdjList[4].push_back(e);

    e.Cost =14; e.EndV = 0;
    AdjList[5].push_back(e);
    e.Cost = 2; e.EndV = 2;
    AdjList[5].push_back(e);
    e.Cost = 9; e.EndV = 4;
    AdjList[5].push_back(e);

    StartV = 0;
    Dijkstra();
    for(int i = 0; i < NVertices; i++){
        printf("%d : %d\n", i, MinCost[i]);
    }


    for(int i = 0; i < NVertices; i ++){
    for(int j = 0; j < NVertices; j ++){
        AdjMat[i][j] = INFTY;
    }

    }

    AdjMat[0][1] = 7;
    AdjMat[0][2] = 9;
    AdjMat[0][5] = 14;

    AdjMat[1][0] = 7;
    AdjMat[1][2] = 10;
    AdjMat[1][3] = 15;

    AdjMat[2][0] = 9;
    AdjMat[2][1] = 10;
    AdjMat[2][3] = 11;
    AdjMat[2][5] = 2;

    AdjMat[3][1] = 15;
    AdjMat[3][2] = 11;
    AdjMat[3][4] = 6;

    AdjMat[4][3] = 6;
    AdjMat[4][5] = 9;

    AdjMat[5][0] = 14;
    AdjMat[5][2] = 2;
    AdjMat[5][4] = 9;

    dijkstraN2(6, 0);
    for(int i = 0; i < NVertices; i++){
        printf("%d : %d\n", i, MinDist[i]);
    }


    return 0;
}
