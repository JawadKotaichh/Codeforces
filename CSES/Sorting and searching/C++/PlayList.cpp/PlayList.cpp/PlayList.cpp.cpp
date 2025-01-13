#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

int longest_Sequence(int n, const list<int>& L) {
    map<int, int> D;  // Map to track last seen positions
    int maxLong = 0;
    int start = 0;  // Start of the window
    int end = 0;    // End of the window
    
    vector<int> vec(L.begin(), L.end());  // Convert list to vector for indexing

    while (end < n) {
        int currElement = vec[end];
        
        // If element is already in the map, move start to avoid duplication
        if (D.find(currElement) != D.end()) {
            start = max(start, D[currElement] + 1);
        }

        // Update the element's last seen position
        D[currElement] = end;

        // Calculate the current window size and update max length
        maxLong = max(maxLong, end - start + 1);
        end++;
    }

    return maxLong;
}

int main() {
    int n;
    list<int> L;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        L.push_back(num);
    }

    int answer= longest_Sequence(n, L);
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
