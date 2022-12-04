#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 1;
    input >> n;
    std::vector<int> nums(n);
    std::map<int, int> bruh;
    int kappa;
    while(input >> kappa) {
        bruh[kappa]++;
    }

    std::map<int, int>::iterator it = bruh.begin();
    nums[0] = it->first / 2;
    if(it->second == 1) bruh.erase(it->first);
    else bruh[it->first]--;

    for(int i = 1; i < n; i++) {
        int nextMin = (*bruh.begin()).first;
        nums[i] = nextMin - nums[0];
        int toRemove = nums[i] * 2;
        std::cout << toRemove << "\n";
        if(bruh[toRemove] == 1) bruh.erase(toRemove);
        else bruh[toRemove]--;
        for(int j = i - 1; j > -1; j--) {
            int toRemove = nums[i] + nums[j];
            if(bruh[toRemove] == 2) {
                bruh.erase(toRemove);
            }
            else bruh[toRemove] -= 2;
        }
    }
    
    for(auto u : nums) std::cout << u << " ";
}

