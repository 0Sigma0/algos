#include <fstream>

int n = 500002;
int count = 0;
int *DS = new int[n];
int *rank = new int[n];

void make_set(int i) {
    count++;
    DS[i] = i;
    rank[i] = 0;
}

int find(int k) {
    if(k == DS[k]) return k;
    return DS[k] = find(DS[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        count--;
        if(rank[a] < rank[b]) {
            a = b + a;
            b = a - b;
            a = a - b;
        }
        DS[b] = a;
        if(rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    int n, q;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> n >> q;
    for(int i=1; i<n+1; i++) {
        make_set(i);
    }
    for(int i=1; i<q+1; i++) {
        int a, b;
        input >> a >> b;
        merge(a, b);
        output << count << '\n';
    }
}
