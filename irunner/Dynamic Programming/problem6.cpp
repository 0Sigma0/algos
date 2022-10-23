#include <fstream>

int upperBound(int line[], int req_key, int n) {
    int lower_bound = 0;
    int upper_bound = n;
    while (lower_bound < upper_bound) {
        int mid = (upper_bound - lower_bound) / 2 + lower_bound;
        if (req_key >= line[mid]) lower_bound = mid + 1;
        else upper_bound = mid;
    }
    return lower_bound;
}
 
int main() {
    int n;
    std::ifstream input("input.txt");
    input >> n;
    
    int *line = new int[n];
    int *f = new int[n+1];
    f[0] = INT32_MIN;
    for(int i=1; i<=n; i++) {
        f[i] = INT32_MAX;
    }
    
    for(int i=0; i<n; i++) {
        input >> line[i];
    }
    
    for(int i=0; i<n; i++) {
        int k = upperBound(f, line[i], n);
        if(f[k-1] < line[i] && f[k] > line[i]) f[k] = line[i];
    }

    int out = 0;
    for(int i=1; i<=n; i++) {
        if(f[i] != INT32_MAX) {
           out++; 
        }
    }
    std::ofstream output("output.txt");
    output << out;
    input.close();
    output.close();
}

