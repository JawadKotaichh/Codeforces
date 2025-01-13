#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int towers(int n, const vector<int>& cubes) {
    vector<int> towers;

    for (int cube : cubes) {
        auto pos = upper_bound(towers.begin(), towers.end(), cube);
        if (pos == towers.end()) {
            towers.push_back(cube);
        } else {
            *pos = cube;
        }
    }
    return towers.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }

    int answer = towers(n, cubes);
    cout << answer << endl;
    return 0;
}
