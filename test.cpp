# include <iostream>
# include <map>
# include <vector>
using namespace std;

void Mode(vector<int>a, int n){
    map<int,int>D;
    int lastMode=a[0];
    int counter=1;
    vector<int>answer;

    for (int i=0;i<n;i++){
        if (D.find(a[i])!=D.end()){
            D[a[i]]+=1;
        }
        else{
            D[a[i]]=1;
        }
        if (D[a[i]]>=counter){
                counter=D[a[i]];
                lastMode=a[i];
                answer.push_back(a[i]);
            }
            else{
                answer.push_back(lastMode);
            }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
        if (i != answer.size() - 1) cout << " ";  
    }
    cout<<endl;
}
// 1 2 

// a = 1 1 1 2
// b = 1 2 3 4 

// 4 5 1 2 3 6 7 8 
// 1 2 3 4 5 6 7 8 9 10 



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