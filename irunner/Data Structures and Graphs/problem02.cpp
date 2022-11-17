#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int q;
    int i, x;
    int l, r;
    std::string command;
    std::cin >> n;
    
    int *arr = new int[n];
    for(int j=0; j<n; j++) {
        std::cin >> arr[j];
        
    }
    
    std::cin >> q;
    for(int j=0; j<q; j++) {
        std::cin >> command;
        if('A' == command[0]) {
            std::cin >> i >> x;
            arr[i] += x;
        } else {
            int sum = 0;
            std::cin >> l >> r;
            for(int j=l; j<r; j++) {
                sum += arr[j];
            }
            std::cout << sum << '\n';
        }
    }
}

