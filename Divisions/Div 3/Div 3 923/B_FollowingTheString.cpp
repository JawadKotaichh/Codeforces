# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    The list a where a[i] represents the number of such indices
    j<i  that s[i]=s[j]

    Goal is to get the string

    make a map with keys counters and value list of possible letters
    when there is a new counter we delete the last one

*/


string reconstructString(int n, vector<int> a) {
    string s(n, ' ');  
    map <int,vector<char>> counter;
    counter[0]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    for(int i=0;i<n;i++){
        if(counter.find(a[i])!=counter.end()){
            s[i]=counter[a[i]].back();

            counter[a[i]].pop_back();

            if(counter[a[i]].empty()) counter.erase(a[i]);

            counter[a[i] + 1].push_back(s[i]);
        }
    }
    return s;
}

int32_t main(){
    int t; cin>>t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        cout<<reconstructString(n,a)<<endl;

    }
    return 0;
}