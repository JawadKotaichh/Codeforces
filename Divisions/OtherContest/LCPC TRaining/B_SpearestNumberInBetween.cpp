# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define ll long long
# define int ll
using namespace std;

/*
    If a and b or between them there is powers of two the answer is the minimum one bwetwen them

    else: I take all number that has two one bits in their binary representation and get the minimum between them

*/

bool isPowerOfTwo(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

int findPowerOfTwoInRange(int a, int b) {

    int power = ceil(log2(a));
    int smallestPowerOfTwo = 1 << power; 

    if (smallestPowerOfTwo <= b) {
        return smallestPowerOfTwo;
    }
    return -1;
}

vector<int> generateNumbersWithTwoOnes(int n) {
    vector<int> result;
    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) == 2) {
            result.push_back(i);
        }
    }
    
    return result;
}

int SparsetNumber(int a,int b){
    if (isPowerOfTwo(a)) return a;
    else if(findPowerOfTwoInRange(a,b)!=-1){
        return findPowerOfTwoInRange(a,b);
    }
    else{
        int bitsNumber=floor(log2(b))+1;
        vector<int> lstOfNumberWith2Ones=generateNumbersWithTwoOnes(bitsNumber);
        
        double mini=INFINITY;
        for(int i=1;i<lstOfNumberWith2Ones.size();i++){
            if (a<lstOfNumberWith2Ones[i]<b && lstOfNumberWith2Ones[i]<mini) mini = lstOfNumberWith2Ones[i];
        }
        return mini;


    }
}




int32_t main(){
    int a,b;cin>>a>>b;
    cout<<SparsetNumber(a,b)<<endl;
    return 0;
}

