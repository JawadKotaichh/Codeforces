#include<bits/stdc++.h>
using namespace std;
/*
    Given n programmers
    Any the difference between any two consecutive teammates <=k
    programmer cannot stand directly behind a new teammate they must stay behind thhe same person or on the front of the team
    Goal: Largest possible team they can select while maintaining the skill balance


    ex: 1 2 1 2 6 7 1
    k=4
    1 2 1 2 6 7 --->6

    7 4 7 4 8 9
    k=3
    7 4 7 4 

*/

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int maxCount = 1, left = 0;

    for (int right = 1; right < n; right++) {
        if (abs(a[right] - a[right - 1]) > k) {
            left = right;  
        }
        maxCount = max(maxCount, right - left + 1);
    }

    cout << maxCount << endl;
    return 0;
}