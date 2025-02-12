#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    When we 
    have the letter b: means that we should remove the rightmost lowercase
    have the letter B: means that we should remove the rightmost uppercase
    If there is not we don't change anything.
    

    
*/

string Removed(string s){
    string output="";

    vector<int> listOfUpper;
    vector<int> listOfLower;
    
    for(int i=0;i<s.size();i++){

        if(s[i]=='B'){
            if(listOfUpper.size()!=0){
                s[listOfUpper.back()]='/';
                
                listOfUpper.pop_back();

            }
            s[i]='/';
        }
        else if (s[i]=='b'){
            if(listOfLower.size()!=0){
                
                s[listOfLower.back()]='/';
                listOfLower.pop_back();
            }
            s[i]='/';
        }
        else{
            if(isupper(s[i])){
                listOfUpper.push_back(i);  
            }
            else{
                listOfLower.push_back(i);
            }
        }
    }
    for(int j=0;j<s.size();j++){
        if(s[j]!='/') output+=s[j];
    }


    return output;

}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin>>s;
        cout<<Removed(s)<<endl; 
    }

    return 0;
}
