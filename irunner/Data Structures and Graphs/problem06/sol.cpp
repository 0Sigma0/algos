#include <fstream>
#include <vector>

int main() {
    int numOfNodes, numOfEdges;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> numOfNodes >> numOfEdges;
    std::vector<std::vector<int>> AdjList(numOfNodes+1);
    for(int i=0; i<numOfEdges; i++) {
        int u, v;
        input >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    for(int i=1; i<numOfNodes+1; i++) {
        output << AdjList[i].size();
        for(const auto& x : AdjList[i]) {
            output << " " << x;
        }
        output << '\n';
    }
}
