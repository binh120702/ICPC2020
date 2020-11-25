#include <bits/stdc++.h>
using namespace std;

struct point{
    int64_t x, y;
};

int n, res;
point a[100];

int64_t area(point &x, point &y, point &z){
    return (y.x-x.x)*(y.y+x.y)+(z.x-y.x)*(z.y+y.y)+(x.x-z.x)*(x.y+z.y);
}

bool check(point &x, point &y, point &z, point &t){
    if (area(x, y, z)>0 && area(y, z, t)>0 && area(z, t, x)>0 && area(t, x, y)>0) return true;
    return false;
}

int main()
{
    while (cin >> n){
        if (n==0) break;
        for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
        res=0;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                for(int k=1; k<=n; ++k)
                    for(int t=1; t<=n; ++t)
                        res+=check(a[i], a[j], a[k], a[t]);
        cout << res/4 << '\n';
    }
    return 0;
}
