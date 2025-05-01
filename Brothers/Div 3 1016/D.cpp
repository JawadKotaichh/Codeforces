#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> get_quadrant_value(ll d, int n)
{
    ll square_size = (1LL << ((2 * n) - 2));

    ll upper_left_start = 1;
    ll upper_left_end = square_size;

    ll bottum_right_start = upper_left_end + 1;
    ll bottum_right_end = bottum_right_start + square_size - 1;

    ll bottum_left_start = bottum_right_end + 1;
    ll bottum_left_end = bottum_left_start + square_size - 1;

    ll upper_right_start = bottum_left_end + 1;
    ll upper_right_end = upper_right_start + square_size - 1;

    if (d >= upper_left_start && d <= upper_left_end)
        return {1, upper_left_start}; // UL
    else if (d >= bottum_right_start && d <= bottum_right_end)
        return {4, bottum_right_start}; // UR
    else if (d >= bottum_left_start && d <= bottum_left_end)
        return {3, bottum_left_start}; // BL
    else
        return {2, upper_right_start}; // BR
}

pair<long long, long long> skibidi_get_x_and_y(ll d, ll n)
{

    if (n == 1)
    {
        if (d == 1)
            return {0, 0}; // UL
        if (d == 2)
            return {1, 1}; // BR
        if (d == 3)
            return {1, 0}; // BL
        if (d == 4)
            return {0, 1}; // UR
    }

    pair<long long, long long> answer = get_quadrant_value(d, n);

    ll q = answer.first;
    ll start = answer.second;
    ll offset = 1LL << (n - 1);

    pair<long long, long long> sub_result = skibidi_get_x_and_y(d - start + 1, n - 1);
    if (q == 1)
        return {sub_result.first, sub_result.second};
    else if (q == 4)
        return {sub_result.first + offset, sub_result.second + offset};
    else if (q == 3)
        return {sub_result.first + offset, sub_result.second};
    else
        return {sub_result.first, sub_result.second + offset};
}

int get_quadrant_coordinates(ll x, ll y, int n)
{
    ll offset = 1LL << (n - 1);
    // UL
    ll upper_left_X_start = 0;
    ll upper_left_X_end = (1LL << (n - 1)) - 1;
    ll upper_left_Y_start = 0;
    ll upper_left_Y_end = (1LL << (n - 1)) - 1;
    // BR
    ll bottum_right_X_start = upper_left_X_end + 1;
    ll bottum_right_X_end = bottum_right_X_start + offset - 1;
    ll bottum_right_Y_start = upper_left_Y_end + 1;
    ll bottum_right_Y_end = bottum_right_Y_start + offset - 1;
    // BL
    ll bottum_left_X_start = bottum_right_X_start;
    ll bottum_left_X_end = bottum_right_X_end;
    ll bottum_left_Y_start = 0;
    ll bottum_left_Y_end = upper_left_Y_end;
    // UR
    ll upper_right_X_start = 0;
    ll upper_right_X_end = upper_left_X_end;
    ll upper_right_Y_start = bottum_right_Y_start;
    ll upper_right_Y_end = bottum_right_Y_end;

    if (upper_left_X_start <= x && upper_left_X_end >= x && upper_left_Y_start <= y && upper_left_Y_end >= y)
        return 1;
    else if (bottum_right_X_start <= x && bottum_right_X_end >= x && bottum_right_Y_start <= y && bottum_right_Y_end >= y)
        return 4;
    else if (bottum_left_X_start <= x && bottum_left_X_end >= x && bottum_left_Y_start <= y && bottum_left_Y_end >= y)
        return 3;
    else
        return 2;
}

ll get_value_from_coordinates(ll x, ll y, int n)
{
    if (n == 1)
    {
        if (x == 0 && y == 0)
            return 1;
        else if (x == 1 && y == 1)
            return 2;
        else if (x == 0 && y == 1)
            return 4;
        else
            return 3;
    }
    int q;
    q = get_quadrant_coordinates(x, y, n);
    ll offset = 1LL << (n - 1);

    if (q == 1)
        return get_value_from_coordinates(x, y, n - 1);
    else if (q == 4)
        return (1LL << ((2 * n) - 2)) + get_value_from_coordinates(x - offset, y - offset, n - 1);
    else if (q == 3)
        return (1LL << ((2 * n) - 1)) + get_value_from_coordinates(x - offset, y, n - 1);
    else
        return (1LL << ((2 * n) - 2)) + (1LL << ((2 * n) - 1)) + get_value_from_coordinates(x, y - offset, n - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < q; ++i)
        {
            string type;
            cin >> type;
            if (type == "<-")
            {
                ll d;
                cin >> d;
                pair<ll, ll> coord = skibidi_get_x_and_y(d, n);
                cout << coord.first + 1 << " " << coord.second + 1 << endl;
            }
            else if (type == "->")
            {
                int x, y;
                cin >> x >> y;
                ll d = get_value_from_coordinates(x - 1, y - 1, n);
                cout << d << endl;
            }
        }
    }
    return 0;
}