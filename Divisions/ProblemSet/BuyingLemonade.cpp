# include <iostream>
# include <algorithm>
# include <numeric>
# include <cmath>
# include<vector>
# define v vector
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    Machine has n slots and n buttons
    the i-th slot contains a[i] cans of lemonade
    When you press i-th button, if there is a lemonade the tot decreases by 1
    else nothing happens
    I know the initial number of cans
    we need to determine the minimum number of button presses to guarantee that 
    we receive at least k cans of lemonade
    When a can Drop we cannot know from which slot
*/

int minimumButtonsPressed(int n,int k, v<int>numberOfCans){
    



}



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        v<int> numberOfCans(n);
        forn(n,i) cin>>numberOfCans[i];
        cout<<minimumButtonsPressed(n,k,numberOfCans)<<endl; 
    }

    return 0;
}