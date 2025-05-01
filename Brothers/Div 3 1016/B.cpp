#include <iostream>
#include <string>
using namespace std;
int min_digits(string s)
{
    int counter = 0;
    bool found = false;
    int indxofRightNumber = -1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != '0')
        {
            found = true;
            indxofRightNumber = i;
            break;
        }
        else
            counter += 1;
    }
    for (int j = 0; j < indxofRightNumber; j++)
    {
        if (s[j] != '0')
            counter += 1;
    }
    return counter;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << min_digits(s) << endl;
    }

    return 0;
}