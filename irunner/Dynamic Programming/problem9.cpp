#include <fstream>
#include <iostream>
#include <algorithm>

int LDS(int line[], int n) {
    int ans = -1;
    int *f = new int[n];
    for(int i=0; i<n; i++) {
        f[i] = 1;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(line[j] != 0 && line[i] % line[j] == 0)
                f[i] = std::max(f[i], f[j] + 1);
        }
    }
    
    for(int i=0; i<n; i++) {
        if(f[i] > ans)
            ans = f[i];
    }
    return ans;
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
            add += 1;
        }
    }
    
    if(add == n) add = 0;
    else if(add != 0) add = 1;
    std::sort(line, line + n);
    std::ofstream output("output.txt");
    if(n == 0) output << 0;
    else output << LDS(line, n) + add;
    input.close();
    output.close();
}

