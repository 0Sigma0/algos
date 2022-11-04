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
            int kappa;
            if(line[j] != 0) kappa = line[i] % line[j];
            else continue;
            if(line[i] % line[j] == 0 && 1 + f[j] > f[i])
                f[i] = 1 + f[j];
        }
    }
    
    for(int i=0; i<n; i++) {
        if(f[i] >= ans)
            ans = f[i];
    }
    return ans + 1;
}

int main() {
    int n;
    int add = 0;
    std::ifstream input("input.txt");
    input >> n;
    int *line = new int[n];
    for(int i=0; i<n; i++) {
        int temp;
        input >> temp;
        line[i] = abs(temp);
    }
    
    for(int i=0; i<n; i++) {
        if(line[i] == 0) {
            add = 1;
            break;
        }
    }
    std::sort(line, line + n);
    std::ofstream output("output.txt");
    output << LDS(line, n) + add;
    input.close();
    output.close();
}


