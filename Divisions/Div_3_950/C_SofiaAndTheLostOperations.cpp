#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long
using namespace std;


/*
    We have an array of n integers she appplied m modifications on it
    (c[i],d[i]) the elemnt of the array with index c[i] should be assigned to d[i]
    This means that a[c[i]] = d[i]

    We have the values of the list a, list d, list b which is the goal, list of c is not present


    After doing all these modifications, we have a list b

    We need to check if there such modifications that transform the list a into b

    So first we can do only m modifications
    
    4
    3 1 7 8
    2 2 7 10
    5
    10 3 2 2 1

    NB: The indexes should be sequential


*/

void IsPossible(int n,vector<int>intialArray,vector<int>goalArray,int numberOfOps,vector<int> valuesOfTheNewElements){
    bool possible=true;
    
    map<int, vector<int>> needed;
    for (int i = 0; i < n; i++) {
        if (intialArray[i] != goalArray[i]) {
            needed[goalArray[i]].push_back(i);
        }
    }


    map<int,int> countOfElementsInD;

    for(int j=0;j<numberOfOps;j++){
        if(countOfElementsInD.find(valuesOfTheNewElements[j])!=countOfElementsInD.end()){
            countOfElementsInD[valuesOfTheNewElements[j]]+=1;
        }
        else{
            countOfElementsInD[valuesOfTheNewElements[j]]=1;
        }
    }
    
    vector<int> excessModifications;

    for (int value : valuesOfTheNewElements) {
        if (!needed[value].empty()) {
            needed[value].pop_back();
        } else {
            excessModifications.push_back(value);
        }
    }

    for (const auto& [key, indices] : needed) {
        if (!indices.empty()) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}









int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n; cin>>n;
        vector<int>intialArray(n);
        vector<int>goalArray(n);
        forn(n,i) cin>>intialArray[i];
        forn(n,i) cin>>goalArray[i];
        int numberOfOps; cin>>numberOfOps;
        vector<int>valuesOfTheNewElements(numberOfOps);
        forn(numberOfOps,i) cin>>valuesOfTheNewElements[i];
        
        IsPossible(n,intialArray,goalArray,numberOfOps,valuesOfTheNewElements);

    }

    return 0;
}
