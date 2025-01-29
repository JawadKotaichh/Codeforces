# include <iostream>
# include <map>
# include <vector>
using namespace std;

// p=new int(n) the value only accessible using p
// we are working on the heap which is the rest of the memory 
// when we do something on the heap after the oricess is finished we should delete the values saved on the heap (delete) but it is still abel to use it using the stack
//  In the stack there is no gap between the adresses where the varuable balues are stored but the heap is not like this
// If ae are trying to allocate something but there no space for it, then the pointer will return null, we are intialising something using the pointer

int main(){

    int x=9;
    cout<<"Adress of x: "<< &x<<endl;
    int *p=&x;
    cout<<"p= "<<p<<endl;


    int * * p2=&p;
    cout<<"P2= "<<**p2<<endl;


    p=new int[10];
    cout<<*p<<endl;
    p[0]=1;
    p[1]=2;

    // cout<<p[0];
    delete p;
    cout<<p<<endl;
    cout<<p[0]<<endl;
    
    int * * p3=new int *;
    *p3=&x;
    cout<<**p3<<endl;


    return 0;
}