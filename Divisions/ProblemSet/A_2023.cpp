/*
    Alice has a coins but she needs b coins to open a bank deposit Profitable
    Unprofitable can be opened with anay ammount of coins
    When she opens ann unprofitable account with x coins, the required number of coins
    to open Profitable decreases by 2*x
    But these coins cannot be deposited in the porfitable account later on

    Our goal is to decrease the required Ammount to be less or equal to left number of coins
*/
# include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int aliceCoins,requiredAmProf;
        cin>>aliceCoins>>requiredAmProf;

        
        if (aliceCoins>=requiredAmProf) cout<<aliceCoins<<endl;
        else{
            if (aliceCoins*2 <= requiredAmProf) cout<<0<<endl;
            else{
                int x=requiredAmProf-aliceCoins;
                if(x>=aliceCoins) cout<<0<<endl;
                else cout<<aliceCoins-x<<endl;
            }
        }

    

    }
    return 0;
}