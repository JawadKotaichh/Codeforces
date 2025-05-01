#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isprime(int n)
{
    if (n == 1)
        return false;

    bool prime = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}

bool isSimple(int x, int k)
{

    if (k == 1)
    {
        if (isprime(x))
        {
            return true;
        }
        return false;
    }
    else if (x == 1)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += pow(10, i);
        }
        return isprime(sum);
    }
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        int k;
        cin >> x >> k;
        if (isSimple(x, k))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}