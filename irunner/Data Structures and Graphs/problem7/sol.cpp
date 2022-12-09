#include <fstream>
#include <vector>
#include <algorithm>

int invert(int c) {
    return c == 1 ? 2 : 1;
}

void dfs(std::vector<std::vector<int>> &AdjList, std::vector<int> &color, int c, int v, std::ofstream &output) {
    color[v] = c;
    for (int u : AdjList[v]) {
        if (color[u] == 0) {
            dfs(AdjList, color, invert(c), u, output);
        } else if (color[u] == c) {
            output << "NO";
            exit(0);
        }
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    std::vector<bool> visited(n+1, false);
    std::vector<bool> part(n+1, false);
    std::vector<std::vector<int>> AdjList(n + 1);
    std::vector<int> color(n + 1);

    //inversion of the input matrix
    for(int i = 1; i < n + 1; i++) {
        color[i] = 0;
        for(int j = 1; j < n + 1; j++) {
            int k;
            input >> k;
            if(!k && (i != j)) AdjList[i].push_back(j); 
        }
    }
    
    for(int v = 1; v < n + 1; v++) {
        if(color[v] == 0) {
            dfs(AdjList, color, 1, v, output);
        }
    }
    
    std::vector<int> sizeOfBipartiteParts(2);
    for(int i = 0; i < n; i++) {
        if(color[i+1] == 1) sizeOfBipartiteParts[0]++;
        else sizeOfBipartiteParts[1]++;
    }
    
    int max = *max_element(sizeOfBipartiteParts.begin(), sizeOfBipartiteParts.end());
    int min = *min_element(sizeOfBipartiteParts.begin(), sizeOfBipartiteParts.end());
    
    if((float)max / min > 2) {
        output << "NO";
    }
    else {
        bool done = false;
        for(int i = 1; i < n + 1; i++) {
            if(sizeOfBipartiteParts[0] == max && color[i] == 1) {
                
                output << i << " ";
                done = true;
            }
            else if(!done && color[i] == 2) output << i;
        }
        output << "\nYES";
    }
}

