#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    Two installations
    The first installation launch fireworks every a minutes
    The second installation launch fireworks every b minutes
    
    Each firework is visible in the in the sky for m+1 minutes
    ex: if a firework is lauched at x minutes
        then x+m inclusive
    
    Goal is to get the maximum number of fireworks that can be seen at the same time
    
    If a firework is launched m minutes after another one, both will show in the sky for one minute

    ex: a=3, b=7, m=4

    the first at 3-->6-->9-->12-->15 ...
    the second at 7--->14-->21 ...

    
*/


int maxAll(int a,int b, int c){
    
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a,b,m; cin>>a>>b>>m;

        cout<<maxAll(a,b,m)<<endl;

    }

    return 0;
}
