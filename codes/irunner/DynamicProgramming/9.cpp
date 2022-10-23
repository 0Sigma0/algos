#include <fstream>
#include <iostream>
#include <algorithm>

int LDS(int line[], int n) {
    int ans = 0;
    int *f = new int[n];
    for(int i=0; i<n; i++) {
        f[i] = 0;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(line[i] % line[j] == 0 && 1 + f[j] > f[i])
                f[i] = 1 + f[j];
        }
    }
    
    for(int i=0; i<n; i++) {
        if(f[i] > ans)
            ans = f[i];
    }
    return ans + 1;
}

int main() {
    int n;
    std::ifstream input("input.txt");
    input >> n;
    int *line = new int[n];
    for(int i=0; i<n; i++) {
        input >> line[i];
    }
    std::sort(line, line + n);
    std::ofstream output("output.txt");
    output << LDS(line, n);
    input.close();
    output.close();
}
