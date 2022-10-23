#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int max(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

void LCS(char A[], char B[], int n){  
    int **L = new int*[n+1];
	for (int i=0; i<=n; i++){
		L[i] = new int[n+1];
	}
	
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if(A[i-1] == B[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else L[i][j] = max(L[i - 1][j], L[i][j - 1]);   
        }
    }
    
    vector<int> AAA;
    vector<int> BBB;
    int k = n;
    int t = n;
    while (L[k][t] != 0) {
        if (A[k] == B[t]) {
        AAA.push_back(k-1);
        BBB.push_back(t-1);
        k--;
        t--;
        } else if (L[k-1][t] == L[k][t]) {
            k--;
        } else {
          t--;
        }
    }
    
    cout << L[n][n];
    cout << '\n';
    for(int i=AAA.size()-1; i>=0; i--) {
        cout << AAA[i] << " ";
    }
    cout << '\n';
    for(int i=BBB.size()-1; i>=0; i--) {
        cout << BBB[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    char *A = new char[n];
    char *B = new char[n];
    
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    
    for(int i=0; i<n; i++) {
        cin >> B[i];
    }
    
    LCS(A, B, n);
}

