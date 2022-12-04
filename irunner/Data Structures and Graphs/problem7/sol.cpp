#include <fstream>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int numOfStudents = 0;
    input >> numOfStudents;
    std::vector<std::vector<int>> AdjList(numOfStudents + 1);
    for(int i = 1; i < numOfStudents + 1; i++) {
        for(int j = 1; j < numOfStudents + 1; j++) {
            int k;
            input >> k;
            if(k || i == j) AdjList[i].push_back(j); 
        }
    }
    std::vector<int> numOfPairings(numOfStudents + 1);
    std::vector<int> numOfSamePairings(numOfStudents + 1);
    std::set<int> tempSet;
    for(int i = 1; i < numOfStudents + 1; i++) {
        for(int j = 1; j < numOfStudents + 1; j++) {
            if(AdjList[i] == AdjList[j] && i != j) {
                numOfPairings[i]++;
            }
        }
    }
    std::cout << "numOfPairings: ";
    for(int i = 1; i < numOfStudents + 1; i++) std::cout << numOfPairings[i] << " ";
    std::cout << "\n";
    for(int i = 1; i < numOfStudents + 1; i++) {
        tempSet.insert(numOfPairings[i]);
    }
    if(tempSet.size() > 2) {
        output << "NO";
        return 0;
    }
    for(int i = 1; i < numOfStudents + 1; i++) {
        for(int u : tempSet) {
            if(numOfPairings[i] == u) numOfSamePairings[u]++;
        }
    }
    std::cout << "numOfSamePairings: ";
    for(int i = 1; i < numOfStudents + 1; i++) std::cout << numOfSamePairings[i] << " ";
    std::cout << "\n";
    std::vector<int> bruh;
    for(int u : numOfSamePairings) {
        if(u != 0) bruh.push_back(u);
    }
    std::cout << "bruh: ";
    for(int u : bruh) std::cout << u << " ";
    int max = *max_element(bruh.begin(), bruh.end());
    int min = *min_element(bruh.begin(), bruh.end());
    if((float)max / min > 2) {
        output << "NO";
    } else {
        if(numOfStudents == 2){ 
            output << "YES\n1";
            return 0;
        }
        int kappa = 0;
        for(int i = 1; i < numOfStudents+1; i++) { 
            if(numOfSamePairings[i] == max) kappa = i;
        }
        output << "YES\n";
        for(int i = 1; i < numOfStudents + 1; i++) {
            if(numOfPairings[i] == kappa) output << i << " ";
        }
    }
}

