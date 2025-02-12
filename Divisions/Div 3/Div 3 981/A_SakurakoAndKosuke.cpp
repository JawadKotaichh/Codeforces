# include <iostream>
# include <vector>
using namespace std;

/*
    the dot is at x=0 first
    at the i-th move the player can move the dot 
    in the a diretion (2*i)-1 units
    Sakurako---> negative direction
    Kosuke-----> positive direction
    The game continues while -n <= x <=n
    Our goal is to determine who will make the last turn

*/



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; 
    while (t--) {   
        int n;
        cin>>n;
        if (n%2!=0) cout<<"Kosuke"<<endl;
        else cout<<"Sakurako"<<endl;
    }
    return 0;
}