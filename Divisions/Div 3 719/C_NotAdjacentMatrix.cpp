#include <bits/stdc++.h>
using namespace std;

/*
    a and b are adjacent if abs(a-b) = 1
    n by n square matrix

    for cell (r,c) 
    cells  (r,c−1), (r,c+1), (r−1,c) and (r+1,c) are adjacent to it.

    we want to generate the cells such as they are not adjacent 
    we can use numbers from 1 to n^2

    ex: n=2 numbers are 1 2 3 4 does not works
     
    ex: n=3 numbers are 1 2 3 4 5 6 7 8 9

    1 6 9
    4 2 7
    8 5 3
    so let's try to fill it diagonal by diagonal



*/

void fillDiagonals(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> diagonalsOrder;
    
    for (int d = 0; d < n; d++) {
        diagonalsOrder.push_back(d);    
        if (d != 0) diagonalsOrder.push_back(-d); 
    }
    
    sort(diagonalsOrder.begin(), diagonalsOrder.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    int num = 1;

    for (int d : diagonalsOrder) {
        if (d >= 0) {
            for (int i = 0; i < n - d; i++) {
                matrix[i][i + d] = num++;
            }
        } else {
            for (int i = 0; i < n + d; i++) {
                matrix[i - d][i] = num++;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t--)
    {
        int n; cin>>n;
        if (n==2) cout<<-1<<endl;
        else fillDiagonals(n);
    }
    

    return 0;
}
