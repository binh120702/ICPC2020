#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define _F(i,a,b) for (int i = a; i >=b; i--)
#define ll long long

using namespace std;
const int mn = 1e5 +5 , base = 1e9+7;
int     n,d,slen[mn],w[mn];
char    s[mn][55];
long long chinhHop[mn][55],mul[10000][55],num[10000][55],dd[10000][55];

void    init()
{
    FOR(i,0,100000) chinhHop[i][0]=1;
    FOR(i, 1, 100000)
        FOR(j, 1, 54)
            chinhHop[i][j]=chinhHop[i][j-1]*(i-j+1)%base;
}

void    solve()
{
    long long res2=0;
    FOR(i,1,d) if (slen[i]==n)
    {
        long long res = 1;
        num[s[i][0]][n]--;
        FOR(j,0,n-1)
        {
            mul[s[i][j]][w[j+1]]++;
            dd[s[i][j]][w[j+1]] = 0;
        }
        FOR(j,0,n-1)
        {
            if (!dd[s[i][j]][w[j+1]])
                res=res*chinhHop[  num[s[i][j]][w[j+1]] ][  mul[s[i][j]][w[j+1]]  ] % base;
            mul[s[i][j]][w[j+1]]--;
            dd[s[i][j]][w[j+1]] = 1;
        }
        num[s[i][0]][n]++;

        res2+=res;
        res2%=base;
    }
    cout << res2<<'\n';
    FOR(i,1,d) num[s[i][0]][slen[i]] --;
}

int main()
{
    freopen("a.inp", "r", stdin);
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i,1,n) cin >> w[i];
        cin >> d;
        FOR(i,1,d)
        {
            cin >> s[i] ;
            slen[i] = strlen(s[i]);
            num[s[i][0]][slen[i]] ++;
        }
        solve();
    }
    return 0;
}
