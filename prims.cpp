#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_i;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min){
            min = key[v];
            min_i = v;
        }

    return min_i;
}

void printMST(int parent[], vector<vector<int>> graph, int n) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \t\t" << graph[i][parent[i]] << " \n";
}

void prim(vector<vector<int>> graph, int n) {
    {
        int parent[n];
        int key[n];
        bool mstSet[n];

        for (int i = 0; i < n; i++){
            key[i] = INT_MAX;
            mstSet[i] = false;
            }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < n - 1; count++) {
            int u = minKey(key, mstSet, n);
            mstSet[u] = true;

            for (int v = 0; v < n; v++)
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                    parent[v] = u;
                     key[v] = graph[u][v];
                }
        }
        printMST(parent, graph, n);
    }
}

int main() {
    int n;
    vector<vector<int>> graph;

    cout << "Enter the number of vertices: "; cin >> n;

    for(int i = 0; i < n; i++) {
        vector<int> v;
        for(int j = 0; j < n; j++) {
            int w;
            cout << "Enter weight for edge " << i << " - " << j << ": "; 
            cin >> w;
            v.push_back(w);
        }
        graph.push_back(v);
    }

    prim(graph, n);

    return 0;
}
