#include <iostream>
#include <cmath>
using namespace std;

long long max_coins(long long n) {
    long long coins = 1;
    while (n > 3) {
        n /= 4;
        coins *= 2;
    }
    return coins;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        long long n;
        cin >> n;
        cout << max_coins(n) << endl;  
    }
    return 0;
}
