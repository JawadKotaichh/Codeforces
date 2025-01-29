#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    The tent can accomodate up to 3 people

    Among the participants, there a introverts, b extroverts, and c universals
    
    Each introvert wants live in a tent alone, a tent that contains only one introvert
    Each extrovert lives exacty with 2 people, so the tent contains 3 pepole ecatly

    Each universal can live with one,two,three

    Goal is the minimum number of tent needed to put in order to get all seated
    If there is no way to sit all those output -1

    N=number of tents needed
    Each introvert want a tent
    Extrovert should be with 2 others otherwise cannot put them in a tent
    
    ex: 1 2 3 
    n=1+1+1

    ex: 1 4 1

    n=1 (1 introvert)
    we need to see if there is a way to put the extroverts in a way where the tent contains 3
    1 extro 2 uni
    2 extro 1 uni
    3 extro 0 uni

    the remaining uni can be seated in a way to full 3 in each tent if the remainign is less than 3 then they need one tent more



*/
int minTents(int a,int b, int c){
    int required=a;
    int numberOfExtro = b/3;
    //cout<<"NumberOfExtro = "<<numberOfExtro<<endl;
    required+=numberOfExtro;
    int remainingB = b-numberOfExtro*3;
    //cout<<"B= "<<b<<endl;

    if(remainingB==0){
        int numberOfUni=c/3;
        required+=numberOfUni;
        int remainingUni=c-numberOfUni*3;
        // cout<<"RemainigUni= "<<remainingUni<<endl;
        if (remainingUni>0) return required+1;
        else return required;
    }

    else if(remainingB==1){
        if(c>=2){
            required+=1;
            c-=2;
            int numberOfUni=c/3;
            required+=numberOfUni;
            int remainigUni=c-numberOfUni*3;
            if(remainigUni==0) return required;
            else return required+1;
        }
        else return -1;


    }
    else{
        // remainingB=2
        if (c>=1){
            required+=1;
            c-=1;
            int numberOfUni=c/3;
            required+=numberOfUni;
            int remainigUni=c-numberOfUni*3;
            if(remainigUni==0) return required;
            else return required+1;   
        }
        else return -1;
    }
    
    
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a,b,c; cin>>a>>b>>c;

        int numberOfTents=a;
        cout<<minTents(a,b,c)<<endl;

    }

    return 0;
}
