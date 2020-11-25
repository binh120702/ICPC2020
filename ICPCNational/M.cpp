#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    ll x1,x2,y1,y2,ans,tx1,tans;
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2)
        {

            swap(y1,y2);
        }
        if (x1>x2)
        {
            swap(x1,x2);
        }

        tx1=x1;
        ans = abs(y2-y1) * 2;
        x1 += abs(y2-y1);
        ans += abs(x2-x1)*2;
        if (abs(x2-x1) % 2 == 1) ans--;

        tans = abs(tx1-x2) * 2;
        y1 += abs(tx1-x2);
        tans += abs(y1-y2) * 2;
        if (abs(y1-y2) %2 == 1) tans--;

        cout << min(tans, ans) << '\n';
    }
    return 0;
}
