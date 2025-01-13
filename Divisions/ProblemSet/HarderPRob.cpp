# include<iostream>
# include <vector>
# include<set>
# include <map>
# include <algorithm>
using namespace std;



void Mode(vector<int>a, int n){

    vector<int>answer;
    map<int,int>D;
    set <int> s;
    
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    for(int i=0;i<n;i++){
        s.erase(a[i]);    
    }

   


    for(int i=0;i<n;i++){
        auto it=s.begin();
        if (D.find(a[i])!=D.end()){
            // element found in D
            answer.push_back(*it);
            
            D[*it]=1;
           s.erase(*it);
            
        }
        else{
            answer.push_back(a[i]);
            D[a[i]]=1;
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
        if (i != answer.size() - 1) cout << " ";  
    }
    cout<<endl;

}


int main(){


    int t;
    cin>>t;
    
    while (t--) {
        int n;
        cin >> n;  

        vector<int> a(n);  
        for (int i = 0; i < n; i++) {
            cin >> a[i];  
        }
        Mode(a,n);
    }
    return 0;
}