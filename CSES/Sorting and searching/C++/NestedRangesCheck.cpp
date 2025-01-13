#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct CompareBySecond
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    }
};
struct CustomComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first) {
            return a.second > b.second;  // Sort second in descending order
        }
        return a.first < b.first;  // Sort first in ascending order
    }
};

void checkRanges(int n, vector<pair<int, int>>& OrderedVectorBasedOnStart)
{
    
    vector<int> containsAnother(n, 0);
    vector<int> containedInOther(n, 0);
    multiset<pair<int, int>, CompareBySecond> OrderedBasedOnEndTime;
    map<pair<int, int>, int> Indexes;

    // two sets one contains all the pairs sorted by the start
    //  and the second contains the already seen pairs sorted based in the end time.

    for (int i = 0; i < n; i++)
    {
        Indexes[OrderedVectorBasedOnStart[i]] = i;
    }

    int maxEnd = 0;
    int indexOfTheMaxEnd = 0;

    sort(OrderedVectorBasedOnStart.begin(), OrderedVectorBasedOnStart.end(), CustomComparator());
    maxEnd = OrderedVectorBasedOnStart[0].second;

    // This part aims to check if each range is contained in another one

    for (int i = 1; i < n; i++)
    {

        if (maxEnd >= OrderedVectorBasedOnStart[i].second)
        {
            containedInOther[Indexes[OrderedVectorBasedOnStart[i]]] = 1;
        }
        else
        {
            maxEnd = OrderedVectorBasedOnStart[i].second;
        }
    }

    OrderedBasedOnEndTime.insert(OrderedVectorBasedOnStart[0]);

    // This part aims to check if each of these ranges contains another range
    for (int i = 1; i < n; i++)
    {
        // cout << "Current Pair= (" << OrderedVectorBasedOnStart[i].first << "," << OrderedVectorBasedOnStart[i].second << ")" << endl;

        while (!OrderedBasedOnEndTime.empty())
        {
            auto pointerToMaxEnd = prev(OrderedBasedOnEndTime.end());
            pair<int, int> value = *pointerToMaxEnd;

            if (value.second >= OrderedVectorBasedOnStart[i].second)
            {
                // cout << "CurrentMax= (" << value.first << "," << value.second << ")" << endl;
                containsAnother[Indexes[value]] = 1;
                OrderedBasedOnEndTime.erase(pointerToMaxEnd);
            }
            else
            {
                break;
            }
        }

        OrderedBasedOnEndTime.insert(OrderedVectorBasedOnStart[i]);
    }

    for (int val1 : containsAnother)
    {
        cout << val1 << " ";
    }
    cout << endl;
    for (int val : containedInOther)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> OrderedVectorBasedOnStart(n);

    for (int i = 0; i < n; i++) {
        cin >> OrderedVectorBasedOnStart[i].first >> OrderedVectorBasedOnStart[i].second;
    }

    checkRanges(n, OrderedVectorBasedOnStart);
    return 0;
}