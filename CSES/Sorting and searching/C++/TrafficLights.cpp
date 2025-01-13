# include <iostream>
# include <vector>
# include <map>
#include <set>

using namespace std;


int main() {
    int x, n;
    cin >> x >> n;
    vector<int> positions(n);

    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    set<int> lights = {0, x};  
    multiset<int> segments = {x};  

    for (int i = 0; i < n; i++) {
        int p = positions[i];

        
        auto upper = lights.upper_bound(p);
        auto lower = prev(upper);

        
        segments.erase(segments.find(*upper - *lower));

        segments.insert(p - *lower);
        segments.insert(*upper - p);

        lights.insert(p);

        cout << *segments.rbegin() << " ";
    }
    cout << endl;
    return 0;
}