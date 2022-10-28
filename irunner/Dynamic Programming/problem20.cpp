#include <fstream>
#include <vector>
#include <string>
using namespace std;

int max(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

int main() {
    int n;
    string As;
    ifstream input("input.txt");
    ofstream output("output.txt");
    getline(input, As);
    n = As.size();
    char *A = new char[n+1];
    char *B = new char[n+1];
    
    for(int i=0; i<=n; i++) {
        A[i+1] = As[i];
    }
    
    for(int i=1; i<=n; i++) {
        B[i] = A[n-i+1];
    }
    
    int **L = new int*[n+1];
    for (int i=0; i<n+1; i++){
        L[i] = new int[n+1];
    }
	
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if(A[i] == B[j]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else L[i][j] = max(L[i - 1][j], L[i][j - 1]);   
        }
    }
    output << L[n][n] << '\n';
    
    vector<int> Aind;
    int k = n;
    int t = n;
    while(k > 0 && t > 0) {
        if(A[k] == B[t]) {
            Aind.push_back(k-1);
            k--;
            t--;
        } else if(L[k-1][t] == L[k][t]) {
            k--;
        } else {
            t--;
        }
    }
    for(int i=Aind.size()-1; i>=0; i--) {
        output << A[Aind[i]+1];
    }
}

