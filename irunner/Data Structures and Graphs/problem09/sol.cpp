#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &AdjList, std::vector<int> &ord, std::vector<bool> &visited, int &id, int v) {
    if(!visited[v]) {
        visited[v] = true;
        ord[v] = id;
        id++;    
    }
    for(int u : AdjList[v]) {
        if(!visited[u]) {
            dfs(AdjList, ord, visited, id, u);
        }
    }
} 

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
        dfs(AdjList, ord, visited, id, i);
    }
    for(int i=1; i<n+1; i++) output << ord[i] << " ";
}

