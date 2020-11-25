// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 44;
int     n,m,a[mn][mn],mid,des[mn],res[1200000][2], sol;

void	enter()
{
    cin>>n>>m;
    int u,v;
    FOR(i,1,m)
    {
        cin>>u>>v;
        a[u][v] = a[v][u] = 1;
    }
}

void    att(int i, int val, int cnt)
{
    // val is list of destroyed node
    if (i>mid)
    {
        FOR(j,1,mid-1) if (des[j] || des[j+1] || !a[j][j+1]) cnt++;
        if (!des[mid])
                res[val][1] = min(res[val][1], cnt);
        else    res[val][0] = min(res[val][0], cnt);
        return;
    }
    // destroy
    des[i] = 1;
    att(i+1, val|(1<<(i-1)), cnt+1);

    // not destroy
    des[i] = 0;
    FOR(j,1,i-2) if (!des[j] && a[i][j]) return;
    att(i+1, val, cnt);
}

void    init()
{
    sol = n*n;
    mid = (n/2);
    FOR(i,0,(1<<mid)-1) res[i][0] = res[i][1] = n*n;
}

void    reAtt(int i, int val, int cnt)
{
    if (i>n)
    {
        FOR(j,mid+1,n-1) if (des[j] || des[j+1] || !a[j][j+1]) cnt++;
        sol = min(sol, cnt+1+min(res[val][0],res[val][1]));
        if (!des[mid+1] && a[mid][mid+1]) sol = min(sol, cnt+res[val][1]);
        return;
    }
    // destroy
    des[i] = 1;
    reAtt(i+1, val, cnt+1);

    // not destroy
    des[i] = 0;
    FOR(j,mid+1,i-2) if (!des[j] && a[i][j]) return;

    int tVal = val;
    FOR(j,1,mid) if (a[i][j] && j!=i-1) tVal = tVal | (1<<(j-1));
    reAtt(i+1, tVal, cnt);
}

void    reInit()
{
    FORD(i,(1<<mid)-2,0)
    {
        FOR(j,1,mid) if (1&(i>>(j-1))==0)
        {
            int nex = i|(1<<(j-1));
            res[i][0] = min(res[i][0], res[nex][0]);
            res[i][1] = min(res[i][1], res[nex][1]);
        }
    }
}

void	solve()
{
    if (n==1)
    {
        cout<<0; return;
    }

    init();
    att(1, 0, 0);

    reInit();
    reAtt(mid+1, 0, 0);

    cout << sol;
}

int 	main()
{
	freopen("daychuyen.inp","r",stdin);
	freopen("daychuyen.out","w",stdout);

	enter();
	solve();

	return 0;
}
