# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# define v vector
using namespace std;

/*
    All students are in one line
    student with index i has interest a[i]
    you can swap a[i] with a[n-i+1]
    
    The goal is to determine the minimum number of disturbance
    that we can achieve after doing these operations any number of times we want
    
    By disturbance is the number of students that are seated by pairs
    adjacent to each others and have the same interest

    Arrive to the mid and stop swaping because they will be nonsense
    and continue counting the disturbance

*/

int minNumOfDisturbance(int n, v<int>a){
    int minDisurbance=0;

    for(int i=1; i<n/2;i++){
        int indexOfSwap=n-i-1;
        int requireSwap=0;


        if (i>0 && a[i]==a[i-1]) requireSwap+=1;
        if ((indexOfSwap < n-1) && (a[indexOfSwap]==a[indexOfSwap+1])) requireSwap+=1;

        if (requireSwap>0) swap(a[i],a[indexOfSwap]);
    }

    for(int j=0;j<n-1;j++)
    {
        if (a[j]==a[j+1]) minDisurbance+=1;
    }
    return minDisurbance;
    

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 

    while (t--) {   
        int n;
        cin >> n;
        vector<int> array(n);
        
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }
        
        cout << minNumOfDisturbance(n, array) << endl;
    }
    
    return 0;
}