# include <iostream>
# include <vector>
# include <map>
# include<algorithm>
# define v vector
using namespace std;

/*
    we are given a n by n matix where if a[i][j]>0 it is the height of the mountain 
    else it is a lake
    Sakurako can select a square are of mountains 
    and increase the height on this diagonal by one 

    So we need to check for each diagonal that has a negative number 
    the max negative number is the number of times she needs to do her magic

    So in each diagonal wee need to see if ther is negative numbers
    if Yes we want the maximum of them
    and the answer will be the sum of the absolute max negative number in each diagonal
    
    The number of diagonals in nxn matrix is 2*n - 1 going from  top-left to bottom-right
    

*/
int totalNumberOfMagic(int n, v<v<int>> matrix){
    int numberOfMagicRequired=0;
    map<int,int> maxNegNumInDiag;

    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (matrix[i][j]<0){
            int diagonal=i-j;
            if (maxNegNumInDiag.find(diagonal)!=maxNegNumInDiag.end()){
                maxNegNumInDiag[diagonal]=max(-matrix[i][j],maxNegNumInDiag[diagonal]);
            }
            else{
                maxNegNumInDiag[diagonal]=-matrix[i][j];
            }
            }

        }
    }
    for(const auto & pair :maxNegNumInDiag){
        numberOfMagicRequired+=pair.second;
    }
    return numberOfMagicRequired;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; 

    while (t--) {   
        int n;
        cin>>n;

        v<v<int>> matrix(n, v<int>(n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        cout<<totalNumberOfMagic(n,matrix)<<endl;
        
    }
    return 0;
}