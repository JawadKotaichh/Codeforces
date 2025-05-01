#include <iostream>
using namespace std;
/*
    k is an ideal generator if there is an integer n
    that can be represented as the sum of elemts
    of elements of a palindromic array of lenght k
    for all n>=k
    [a1,...,ak/2,...,ak]
    [a1,a2,a3]
    -> 2*sum(a1,...,ak/2) = n for all n>=k
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        if (k % 2 == 0)
            cout << "NO" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
