# include <iostream>
# include <vector>
# include <map>
# include <set>

using namespace std;

int main(){
    int n;
    
    cin >> n;
    
    int counter=0;
    int currPos=0;
    int currLenght=0;
    int lastLenght=n;
    
    vector<int> numbers;

    for (int i=1;i<n+1;i++){
        numbers.push_back(i);
    }
    bool takeIt=false;

    while(numbers.size()!=0){

        vector<int>newNumbers;
        
        for (int i=0;i<numbers.size();i++){
            if(takeIt){
                cout<<numbers[i]<<" ";
                takeIt=false;
            }
            else{
                newNumbers.push_back(numbers[i]);
                takeIt=true;
            }
            
        }
        numbers=newNumbers;

    }
    return 0;


}