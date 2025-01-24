#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;

        map<char, int> difficulty_count;
        for (char ch = 'A'; ch <= 'G'; ++ch) {
            difficulty_count[ch] = 0;
        }
        for (char ch : a) {
            difficulty_count[ch]++;
        }

        int additional_problems = 0;
        for (char ch = 'A'; ch <= 'G'; ++ch) {
            int required = m; 
            int available = difficulty_count[ch];
            if (available < required) {
                additional_problems += required - available;
            }
        }

        cout << additional_problems << endl;
    }

    return 0;
}
