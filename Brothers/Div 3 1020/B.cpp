#include <bits/stdc++.h>
using namespace std;
int mex(vector<int> &arr, int N)
{

    sort(arr.begin(), arr.end());
    int mex = 0;
    for (int idx = 0; idx < N; idx++)
    {
        if (arr[idx] == mex)
        {
            mex += 1;
        }
    }
    return mex;
}

vector<int> slicing(vector<int> &arr, int X, int Y)
{

    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    vector<int> result(Y - X + 1);
    copy(start, end, result.begin());
    return result;
}

vector<int> getPermutation(int n, int x)
{
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        if (i != x)
            answer.push_back(i);
    }
    if (x != n)
        answer.push_back(x);
    return answer;
}

vector<int> Check(vector<int> A)
{
    vector<int> colors;
    for (int i = 0; i < A.size(); i++)
    {
        vector<int> sliced = slicing(A, 0, i);
        colors.push_back(mex(sliced, i + 1));
    }
    return colors;
}

int main()
{
    // vector<vector<int>> Correct = {{1, 0, 3, 2}, {2, 3, 1, 0}, {3, 2, 4, 1, 0}, {0}, {0, 2, 1}, {0}, {1, 2, 0, 3}};
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        vector<int> answer = getPermutation(n, x);
        // cout << "answer: ";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
        // cout << "Colors: ";
        // vector<int> colors = Check(answer);
        // for (int i = 0; i < colors.size(); i++)
        // {
        //     cout << colors[i] << " ";
        // }
        // cout << endl;
        // cout << "The correct colors ";
        // vector<int> correctColors = Check(Correct[j]);
        // for (int i = 0; i < colors.size(); i++)
        // {
        //     cout << correctColors[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}