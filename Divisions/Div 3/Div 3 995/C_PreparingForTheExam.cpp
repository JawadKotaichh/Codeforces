# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    There is n different questions numbered from 1 to n
    m : Number of different lists of questions each n-1 different questions
    Each index i is characterized by one integer a[i] which is the number of the questions not present in the ith list
    
    This means that if a[i]= b b is the number of the question not present in the i-th list
    Monocarp know the answer of k questions, given as list of these questions

    Our goal is to determine for each list of question if Monocarp will pass or not

    

*/

void Pass(int n, int m, int k, v<int>KnownQuestions, v<int> MissingAtEachIndex){
    map <int,int> knownD;

    for(int i=0;i<k;i++) knownD[KnownQuestions[i]] = KnownQuestions[i];
    if (k==n-1){
        for(int j=0; j<m; j++){
        
            if(knownD.find(MissingAtEachIndex[j])!=knownD.end()){
                cout<<"0";
            }
            else cout<<"1";
        }
    }
    else if (k<n-1){
        for (int j=0;j<m;j++) cout<<"0";
    }
    else for (int j=0;j<m;j++) cout<<"1";    
    cout<<endl;

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        vector<int> ListOfMissingQatEachIndex(m);
        vector<int> ListOfKnownQ(k);

        for(int i=0; i<m; i++) cin>>ListOfMissingQatEachIndex[i];
        for(int i=0; i<k; i++) cin>>ListOfKnownQ[i];
        
        Pass(n,m,k,ListOfKnownQ,ListOfMissingQatEachIndex);
    }
    return 0;
}