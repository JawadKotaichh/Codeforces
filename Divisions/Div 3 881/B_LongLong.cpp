# include<iostream>
# include <algorithm>
# include <vector>
# define forn for (int i=0;i<n;i++)
# define v vector
using namespace std;



/*
    Alex can apply as many ops as he wants
    Alex can choose any l,r such that 1 <= l <= r <=n
    and multiply a[l:r] inclusive  by -1 
    Our goal is to have the maximum an minimum possible number of ops
    Maxi will be the sum of the absolute value of all element in the lst

*/

int maxAndMiniOps(int n, v<long long> lst){
    long long maxSum=0;

    forn maxSum+=abs(lst[i]);
    int minNbOfOps=0;

    if (lst.size()==1){
        if (lst[0]<0) {cout<< maxSum<<" ";
        return 1;}
        else{
            cout<< maxSum<<" ";
            return 0;
        }
    }

    bool flag=false;

    v<int> listOfTrue(n);

     bool in_negative_block = false;

        for (int i = 0; i < n; i++) {

            if (lst[i] < 0) {
                if (!in_negative_block) {
                    minNbOfOps++;
                    in_negative_block = true;
                }
            } else if (lst[i] > 0) {
                in_negative_block = false;
            }
        }
    


    cout<<maxSum<<" ";
    return minNbOfOps;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;
        v<long long> lst(n);
        forn cin>>lst[i];
        cout<<maxAndMiniOps(n,lst)<<endl;
    }
    return 0;
}