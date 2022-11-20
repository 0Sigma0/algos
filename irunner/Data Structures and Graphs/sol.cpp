#include <fstream>
#include <vector>

int main() {
    int n;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> n;
    std::vector<int> cList(n+1);
    for(int i=1; i<n+1; i++) {
        int u, v;
        input >> u >> v;
        cList[v] = u;
    }
    for(int i=1; i<n+1; i++) output << cList[i] << " ";
}
