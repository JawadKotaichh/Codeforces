#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// The operations are: 
// (The goal is to make the array empty with the minimum number of operations)
// Take two integers l and r such as l<=r and x=min(b[l:r+1])
// And remove all bi that are equal to x

// Input:
// An array a of lenght n 
// And k(maximum number of steps 
// that you change any number of the array by any integer)

// Ex: 2 3 2
// 2 2 2--> min =2
// remove all

// Ex: 1 2 3 4 5 n=5 k=3
//  2 operations

// Ex: 4 7 1 3 2 4 1 n=7 k=0
// 4 7 3 2 4 1ops
// 7 3 2 1ops
// 3 ops

int Gorilla(int n ,int k , vector<int> L){
   
    map<int,int> counterOfEachElement;

    if (k==n) return 1;
    
    int numberOfUniqueElements;
    set<int> uniqueSet(L.begin(),L.end()); 
    numberOfUniqueElements = uniqueSet.size();

    for (int i=0;i<n;i++){
        if (counterOfEachElement.find(L[i])!= counterOfEachElement.end()){
            counterOfEachElement[L[i]]+=1;
        }
        else{
            counterOfEachElement[L[i]]=1;
        }
    }

    vector<pair<int,int>> listOfCount;

    for (const auto& pair : counterOfEachElement) {
        listOfCount.push_back(pair);
    }

    sort(listOfCount.begin(), listOfCount.end(),
              [](const pair<int, int>& a, const pair<int, int>& b) {
                  return a.second < b.second;});


    sort(L.begin(),L.end());

    int pointerToTheMinCounter=0;

    while (k!=0){
        
        if (listOfCount[pointerToTheMinCounter].second<=k){
            k-=listOfCount[pointerToTheMinCounter].second;
            numberOfUniqueElements-=1;
        } 
        else{
            break;
        }
        pointerToTheMinCounter+=1;
    

    }
    return numberOfUniqueElements;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){

    int n, k;
    cin>>n>>k;
    vector<int>L(n);

    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }

    cout<<Gorilla(n,k,L)<<endl;
    }



    return 0;
}