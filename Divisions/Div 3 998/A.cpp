#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_fibonacciness(int a1, int a2, int a4, int a5) {
    vector<int> candidates = {
        a1 + a2,      
        a4 - a2,      
        a5 - a4       
    };

    int max_count = 0;

    for (int a3 : candidates) {
        int count = 0;
        if (a3 == a1 + a2) {
            count++;
        }
        if (a4 == a2 + a3) {
            count++;
        }
        if (a5 == a3 + a4) {
            count++;
        }
        max_count = max(max_count, count);
    }

    return max_count;
}

int main() {
    int t;cin>>t;
    while(t--){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    cout << max_fibonacciness(a1, a2, a4, a5) << endl;
    }
        return 0;

}
