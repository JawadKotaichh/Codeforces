# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    Array b with k elements
    score = sum from 1 to k of sum form 1 to i of b[i]

    We have n arrays each with m elements
    He want to concatnate them in any order to form a single array

    Goal: Find the maximum possible score he can achieve


*/
int maxSum(int n,int m,vector<vector<int>> arrays){

    vector<pair<int, int>> sumWithIndex(n);

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += arrays[i][j];
        }
        sumWithIndex[i] = {sum, i};  
    }

    sort(sumWithIndex.rbegin(), sumWithIndex.rend());
    vector<int> concatenatedArray;

    for (int i = 0; i < n; ++i) {
        int index = sumWithIndex[i].second;
        concatenatedArray.insert(concatenatedArray.end(), arrays[index].begin(), arrays[index].end());
    }

    int totalScore = 0;
    int cumulativeSum = 0;

    for (int i = 0; i < concatenatedArray.size(); ++i) {
        cumulativeSum += concatenatedArray[i];
        totalScore += cumulativeSum;
    }
    return totalScore;
}


int32_t main(){
    int t;
    cin >> t; 
    
    while (t--) {
        int n, m;
        cin >> n >> m; 
        
        vector<vector<int>> arrays(n, vector<int>(m));  
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arrays[i][j]; 
            }
        }
        cout<<maxSum(n,m,arrays)<<endl;
        
    }
    
    return 0;
}