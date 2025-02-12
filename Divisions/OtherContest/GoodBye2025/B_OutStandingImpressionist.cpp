# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# define v vector
using namespace std;


/*  Explanation of the problem:

    for each i betwen 1 and n, 
    he can only remember li<= wi <=ri

    Impression i is unique iff there is an array
    wi != wj for 1<= j <=n and j != i

    l is the minimum, r is the maximum value for wi
*/

/*
    Example:
    [/3,6/ /2,2/ /1,2/ /1,1/ /3,4/ /2,2/]
    size of the list will be 6
    first  [3,4,4,4,4,4]
    second [] mini=2 and maxi=2 no possible 
    third [] 
    
    ---> if l==r and numberOfImpressions>1 return 0


*/

string Outstanding(int numberOfImpressions,v<int>listOfImpressions){
    // our goal for every i to have wi differrent from the others
    


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; 
    while (t--) {
        int numberOfImpressions;
        v<int> allImpressions;
        cin >> numberOfImpressions;
        for (int i=0;i<numberOfImpressions;i++){
            int l,r;
            cin>>l>>r;
            allImpressions.push_back(l);
            allImpressions.push_back(r);
        }
        cout<<Outstanding(numberOfImpressions,allImpressions)<<endl;
    }

    return 0;
}