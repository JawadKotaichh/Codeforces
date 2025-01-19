#include<bits/stdc++.h>
#define forn(n, i) for (int i = 0; i < n; i++)
#define v vector
using namespace std;

void Possible(int n, int m, vector<vector<int>> cards, vector<int>& cowOrder) {
    int lastCard = -1;
    bool Can = true;
    for (int j = 0; j < m; ++j) {
        if (Can) {
            for (int i = 0; i < n; ++i) {
                if (cards[i][j] == lastCard + 1) lastCard += 1;
                else {
                    Can = false;
                    break;
                }
            }
        } else {
            break;
        }
    }

    if (Can) {
        for (int cow : cowOrder) {
            cout << cow+1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<vector<int>, int>> cowCards; 

        for (int i = 0; i < n; ++i) {
            vector<int> cards(m);
            for (int j = 0; j < m; ++j) {
                cin >> cards[j];
            }
            sort(cards.begin(), cards.end());
            cowCards.push_back({cards, i});
        }

        sort(cowCards.begin(), cowCards.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
            return a.first[0] < b.first[0];
        });

        vector<vector<int>> sortedCards;
        vector<int> cowOrder; 
        for (auto& cow : cowCards) {
            sortedCards.push_back(cow.first);
            cowOrder.push_back(cow.second); 
        }

        Possible(n, m, sortedCards, cowOrder);
    }
    return 0;
}
