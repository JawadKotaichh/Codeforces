#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count += 1;
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c != s[i - 1] && (i + 1 == s.size() || c != s[i + 1]))
                {
                    s[i] = c;
                    break;
                }
            }
        }
    }
    cout << s << endl;

    return 0;
}