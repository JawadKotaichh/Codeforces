# include<iostream>
# include<map>
# include<vector>
# include <algorithm>
using namespace std;


// 2 rows and m columns
// a+b+c is the number of monkeys
// a sit only on row 1
// b only on row 2
// c have no problem

// I want to make as much as possible of the monkeys of a at row 1 
//  as much as possible of monkeys b on row 2 
//  remainig of both rows will br from c
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int remainigRowOne=0;
        int remainigRowTwo=0;
        int totNumberOfMonkeys=0;
        
        if (a>=m){
            totNumberOfMonkeys+=a;
        }
        else{
            remainigRowOne=m-a;
        }

        if (b>=m){
            totNumberOfMonkeys+=b;
        }
        else{
            remainigRowTwo=m-b;
        }
        
        if (remainigRowOne<c){
            totNumberOfMonkeys+=remainigRowOne;
            c-=remainigRowOne;
            if (remainigRowTwo<c){
                totNumberOfMonkeys+=remainigRowTwo;
                c-=remainigRowTwo;
                cout<<totNumberOfMonkeys<<endl;
            }
            else{
                totNumberOfMonkeys+=c;
                cout<<totNumberOfMonkeys<<endl;
            }
        }
        else{
            totNumberOfMonkeys+=c;
            cout<<totNumberOfMonkeys<<endl;
        }
    }
    return 0;
}