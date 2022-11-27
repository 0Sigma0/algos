#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    int id = 1;
    input >> n;
    std::vector<std::vector<int>> AdjList(n+1);
    std::vector<int> ord(n+1);
    std::vector<bool> visited(n+1);
    std::queue<int> q;
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n+1; j++) {
            int k = 0;
            input >> k;
            if(k == 1) AdjList[i].push_back(j);
        }
        std::sort(AdjList[i].begin(), AdjList[i].end());
    }
    for(int i=1; i<n+1; i++) {
        if(!visited[i]) {
            ord[i] = id;
            id++;   
            visited[i] = true;
            q.push(i);
        }
        while(not q.empty()) {
            int v = q.front();
            q.pop();
            for(const auto u : AdjList[v]) {
                if(!visited[u]) {
                    visited[u] = true;
                    ord[u] = id;
                    id++;
                    q.push(u);
                }
            }
        }
    }
    for(int i=1; i<n+1; i++) output << ord[i] << " ";
}
