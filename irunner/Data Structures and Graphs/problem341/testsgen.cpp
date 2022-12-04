#include <iostream>
#include <fstream>
#include <vector> 
#include <random>
#include <algorithm>

int main() {
    std::ofstream output("output.txt");
    std::random_device rnd;
    std::uniform_int_distribution<int> dist(1, 9);
    std::vector<int> vec;
    int n = 5;
    for(int i = 0; i < n; i++) {
        vec.push_back(dist(rnd));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++) {
        std::cout << vec[i] << " ";
    }
    output << n << "\n";
    for(int u : vec) {
        for(int v : vec) {
            output << u + v << " ";
        }
    }

}

