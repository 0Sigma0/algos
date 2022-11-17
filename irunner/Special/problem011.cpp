#include <iostream>
using namespace std;

int main() {
    int n, m; // n - number of nodes, m - number of edge
    cin >> n >> m;
    int **AdjMat = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        AdjMat[i] = new int[n+1];
    }
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjMat[u, v] = w;
        AdjMat[v, u] = w;
    }
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<n+1; j++) {
            cout << AdjMat[i, j] << " ";
        }
            cout << '\n';
    }

}
