#include<iostream>
using namespace std;


class Complex{
    public:
    double real;
    double imag;
    
    Complex(int r,int i){
        real=r;
        imag=i;
    }
    //Constructor
    Complex(const Complex &c){ //Alias of a complex always use const when passing by reference
        real=c.real;
        imag=c.imag;
    }

    // To initialise a function but the function is garanteed that the fucntion will not change the variables we write:
    double SquaredNorm() const{
        return real*real+imag*imag;
    }
};

class Date{
    public:
    int day;
    int month;
    int year;
    
    friend ostream& operator<<(ostream& os, const Date& dt) {
        os << dt.day << "/" << dt.month << "/" << dt.year;
        return os;  // Returning the stream for chaining
    }

    Date operator + (const Date &d) const{ //Implicitly the first Date is present before
       Date result(day+d.day,month+d.month,year+d.year);
       return result;

    }

    //constructor:
    Date(int d=0,int m=0,int y=0){
        day=d;
        month=m;
        year=y;
        // The goal of this is to intialize the class and assign values to the variables
    }

    bool greater(Date d){
        int temp= this->day;//anyfunction fo2; this is a pointer so we acces it by -> or *this.functionName()
        return true;

    }

    
};


int main(){
    Date d(1,1,2007);
    cout<<d.month<<endl;
    Date d2;
    cout<<d2<<endl;
    cout<<d2+d.day<<endl;
    return 0;
}