# include <iostream>
# include <algorithm>
# include <numeric>
# include <cmath>
using namespace std;

// a*k = n and b*j = n 
// a*k = b*j
// a/b = j/k


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long g=gcd(a,b);
        
        if (b%a==0) cout<<b*(b/a)<<endl;
        else cout<<(a*b)/g<<endl;       
        
    }

    return 0;
}