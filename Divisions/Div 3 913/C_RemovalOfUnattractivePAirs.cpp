#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    We have string s of n letters
    He can use any two adjacent letters such as they are differents

    Goal: minimumlenght Possible after ny number of deletions

    try to arrange the string such as each two consecutive letter are differents


    ex: avbvvcvvvd
    a:1 b:1 c:1 d:1 v:6
    4 diff letters
    6 repetitions 

    avbvcvdv vv 2

    ex: aacebeaa
    a:4 b:1 c:1 e:2 
    abacaeae 0
    4 different letters
    4 repetitions

    ex:dbdcfbbdc
    d:3 b:3 c:2 f:1
    dbdbdbcf c 1

    The most repetitve letter will be the one I will put with the other letters
    
    dbcf 4 -> 9 ->5 common-> 
    4 different letters
    5 that are repetitions
    answer=5-4=1


*/
void solve() {
    int n;
    string s;
    cin >> n >> s;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int max_freq = 0;
    for (const auto& [letter, count] : freq) {
        max_freq = max(max_freq, count);
    }

    cout << max(n % 2, 2 * max_freq - n) << endl;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        
        solve();
    }

    return 0;
}
