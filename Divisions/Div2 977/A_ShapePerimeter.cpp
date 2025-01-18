#include <bits/stdc++.h>
# define ll long long
using namespace std;

/*
    m by m square
    we are guven two integers sequence x and y
    for each step from 1 to n we can:
    --> move x[i] to right and y[i] upwards
    --> color the current square m x m


    every x,y is the bottum left corner of a square
    Our aim is to get the perimeter of the overall area

*/
ll Perimeter(int n,int m,vector<int>listOfXandY){
    ll totalPerimeter = n*m*4;
    int startx=0;
    int starty=0;

    for(int i=0;i<2*n;i+=2){
        // cout<<"i="<<i<<endl;

        if (startx==0 && starty==0){
            startx+=listOfXandY[i];
            starty+=listOfXandY[i+1];

        }
        else{
            // cout<<"I="<<i<<endl;
            ll newX=startx+listOfXandY[i];
            ll newY=starty+listOfXandY[i+1];
            // cout<<"NEWX="<<newX<<" NEWY= "<<newY<<endl;
            // cout<<"Startx= "<<startx<<" Starty= "<<starty<<endl;
            if (newX<startx+m && newY<starty+m){
                // newx has extra right and up
                ll widthOfThecomonpart=startx+m-newX;
                ll heightOfTheCommonpart=starty+m-newY;
                totalPerimeter-=((2*widthOfThecomonpart)+(2*heightOfTheCommonpart));
            }

            startx=newX+m;
            starty=newY+m;
        }
    }
    return totalPerimeter;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n,m; cin>>n>>m;//m is the side lenght of the square
        vector<int> listOFXandY;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            listOFXandY.push_back(x);
            listOFXandY.push_back(y);
        }
        cout<<Perimeter(n,m,listOFXandY)<<endl;

    }

    return 0;
}