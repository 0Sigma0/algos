#include <fstream>


int main() {
using namespace std;

    int n, m; // n - number of nodes, m - number of edges
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> n >> m;
    int **AdjMat = new int*[n];
    for(int i=0; i<n; i++) {
        AdjMat[i] = new int[n];
    }
    for(int i=0; i<m; i++) {
        int u, v;
        input >> u >> v;
        AdjMat[u-1][v-1] = 1;
        AdjMat[v-1][u-1] = 1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            output << AdjMat[i][j] << " ";
        }
        output << '\n';
    }
}
