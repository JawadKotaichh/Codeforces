#include <bits/stdc++.h>
using namespace std;
/*
    we have a number x
    and we added a number of zeros to get y
    and he give us n = x + y
    so we need to get all suitable x that could
    have thought of for the given n

*/
vector<unsigned long long> get_possible(unsigned long long n)
{

    vector<unsigned long long> answer;
    for (int i = 1; i <= 18; i++)
    {
        int d = 1 + pow(10, i);
        ;
        if (n % d == 0)
        {
            answer.push_back(n / d);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long n;
        cin >> n;
        auto ans = get_possible(n);
        if (ans.empty())
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans.size() << endl;
            for (size_t i = 0; i < ans.size(); ++i)
            {
                if (i)
                    cout << ' ';
                cout << ans[i];
            }
            cout << endl;
        }
    }

    return 0;
}