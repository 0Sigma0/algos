#include <fstream>
#include <vector>

int main() {
    int n;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> n;
    std::vector<int> cList(n+1);
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n+1; j++) {
            int k;
            input >> k;
            if(k == 1) cList[j] = i;
        }
    }
    for(int i=1; i<n+1; i++) output << cList[i] << " ";
}
