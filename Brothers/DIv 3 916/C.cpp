# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;
/*
    There is n quests numbered from 1 to n
    
    The 1st quest is always available 
    The i-th quest is available if all the quests
    before this one are completed at least once

    For each completion of the ith quest he gains a[i] points for the first completion
    Then b[i] for the other completions

    The maximum number he can complete <=k
    
    Goal: The maximum possible total points he can gain after solving at most k quests

    Every quest to be solved I should solve all quests before it


    ex: maxQuests=7 
    a=[4,3,1,2]
    b=[1,1,1,1]
    1->4
    2->3
    3->1 
    4->2
    1->1
    2->1
    3->1 
    tot=13

    ex: max=2
    a=[1,2,5]
    b=[3,1,8]
    1,1-->4 


    ex: max=5
    a=[3,2,4,1,4]
    b=[2,3,1,4,7]

    1-->3 
    2-->2
    3-->4
    2-->3
    2-->3 
    tot=15

    ex: max=4

    a=[1,4,5,4,5,10]
    b=[1,5,1,2,5,1]

    1->1
    2->4
    3->5
    b->5 
    tot=15

*/

int problemSolved(int n,int k,vector<int>a,vector<int>b ){
    int maxScore=0;
    
    int currScore=0;
    int currSum=0;
    int maxB=0;

    for(int i=0;i<n;i++){
        currSum+=a[i];
        maxB=max(maxB,b[i]);
        if(i<=k-1){
            int remaining=k-i-1;
            currScore+=currSum;
            
            if(remaining>0){
                currScore+= remaining*maxB;
                // cout<<"Max= "<<*max_element(b.begin(),b.begin()+i+1)<<endl;
            }
            
            if(currScore>maxScore) maxScore=currScore;
            currScore=0;

        }
        

    }

    return maxScore;
    

}



int32_t main(){
    int t; cin>>t;

    while(t--){
        int n,k;cin>>n>>k;

        vector<int>a(n);
        vector<int>b(n);
        forn(n,i) cin>>a[i];
        forn(n,i) cin>>b[i];

        cout<<problemSolved(n,k,a,b)<<endl;

    }
    return 0;
}