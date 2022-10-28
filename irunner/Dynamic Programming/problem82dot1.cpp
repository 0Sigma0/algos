#include <fstream>
#include <iostream>
using namespace std;

int LDS(int line[], int n) {
    int ans = 0;
    int *f = new int[n];
    f[0] = 1;
    for(int i=1; i<n; i++) {
        f[i] = 1;
        for(int j=0; j<i; j++) {
            int kappa;
            if(line[j] != 0) kappa = line[i] % line[j];
            else continue;
            if(kappa == 0 && 1 + f[j] > f[i]) f[i] = 1 + f[j];
        }
    }
    ans = f[0];
    for(int i=1; i<n; i++) {
        if(f[i] > ans) ans = f[i];
    }   
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int *line = new int[n];
    for(int i=0; i<n; i++) {
        cin >> line[i];
    }
    int res = n - LDS(line, n);
    cout<< res;
}

