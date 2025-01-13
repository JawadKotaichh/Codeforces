#include<iostream>
#include<string>
using namespace std;




int main(){
   int t;
   cin>>t;
   
   while (t--){
       string s;
       cin>>s;
       int q;
       cin>>q;
       while(q--){
           
           int i,v;
           cin>>i>>v;
           
           if (s.size()<4){
               cout<<"NO"<<endl;
           }
           
           else{
           
           char temp=s[i];
           s[i]=s[v];
           s[v]=temp;
           cout<<s<<endl;
           
           if(s.find("1100")!= std::string::npos){
               cout<<"YES"<<endl;
           }
           else{
               cout<<"NO"<<endl;
           }
       }}
   }
}