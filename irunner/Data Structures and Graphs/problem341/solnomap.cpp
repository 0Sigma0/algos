#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 1;
    input >> n;
    std::vector<int> nums(n);
    std::vector<int> pairSums(n * n);
    
    for(int i = 0; i < n * n; i++) {
        input >> pairSums[i];
    }
    std::sort(pairSums.begin(), pairSums.end());
    for(int u : pairSums) std::cout << u << " ";
    std::cout << "\n";
    int min = pairSums[0];
    int max = pairSums[n * n - 1];
    std::cout << "min " << min << "; max " << max;
    std::cout << "\n";
    std::vector<int> numOfSameSums(max+1);
    for(int u : pairSums) numOfSameSums[u]++;

    for(int u : numOfSameSums) std::cout << u << " ";
    std::cout << "\n";

    nums[0] = min / 2;
    if(numOfSameSums[min] == 1) {
        pairSums.erase(pairSums.begin());
        numOfSameSums[min] = 0;
    } else if(numOfSameSums[min] != 0) {
        numOfSameSums[min]--;
    }
    std::cout << "\n";
    for(int u : pairSums) std::cout << u << " ";
    std::cout << "\n";
    for(int u : numOfSameSums) std::cout << u << " ";
    std::cout << "\n";
    
    for(int i = 1; i < n; i++) {
        int min = pairSums[0];
        std::cout << "min: " << min;
        std::cout << "\n";
        nums[i] = min - nums[0];
        int toRemove = nums[i] * 2;
        std::cout << "toRemove: " << toRemove << "\n";
        if(numOfSameSums[toRemove] == 1) {
            pairSums.erase(std::remove(pairSums.begin(), pairSums.end(), toRemove), pairSums.end());
            numOfSameSums[toRemove] = 0;
        } else if(numOfSameSums[toRemove] != 0) {
            numOfSameSums[toRemove]--;
        }
        
        std::cout << "\n";
        for(int u : pairSums) std::cout << u << " ";
        std::cout << "\n";
        for(int u : numOfSameSums) std::cout << u << " ";
        std::cout << "\n";
        
        for(int j = i - 1; j > -1; j--) {
            int toRemove = nums[i] + nums[j];
            if(numOfSameSums[toRemove] == 2) {
                pairSums.erase(std::remove(pairSums.begin(), pairSums.end(), toRemove), pairSums.end());
                numOfSameSums[toRemove] = 0;
            } else if(numOfSameSums[toRemove] != 0) {
                numOfSameSums[toRemove] -= 2;
            }
        }
    }
    for(int u : nums) output << u << "\n";
}

