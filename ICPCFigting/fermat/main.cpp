// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;
long long l,r,lf,rt,a,b,c,n,m;

void	enter()
{
    cin>>lf>>rt;
}

void    pr()
{
    char tmp;
    if (max(a,b)>=c) tmp = '>'; else tmp='<';
    cout<<a<<'^'<<n<<'+'<<b<<'^'<<n<<tmp<<c<<'^'<<n<<'\n';
}

void	findNum()
{
    long long sum = m*m*m*(m-2) - (m-1)*(m-1)*(m-1)*(m-3);
    while (l>sum)
    {
        l-=sum; m++;
        sum = m*m*m*(m-2) - (m-1)*(m-1)*(m-1)*(m-3);
    }
    bool dd = 0;
    for(a=1; a<=m; a++)
    {
        dd = dd || (a==m);
        sum = m*m*(m-2);
        if (!dd) sum-=(m-1)*(m-1)*(m-3);
        if (l>sum) l-=sum; else break;
    }
    for(b=1; b<=m; b++)
    {
        dd = dd || (b==m);
        sum = m*(m-2);
        if (!dd) sum-=(m-1)*(m-3);
        if (l>sum) l-=sum; else break;
    }
    for(c=1; c<=m; c++)
    {
        dd = dd || (c==m);
        sum = (m-2);
        if (!dd) sum=1;
        if (l>sum) l-=sum; else break;
    }
    if (!dd) n = m ; else n = l+2;
}

void    solve()
{
    while (lf <= rt)
    {
        l = lf++;
        m = 3;
        findNum();
        pr();
    }
}

int 	main()
{
	freopen("fermat.inp","r",stdin);
	freopen("fermat.out","w",stdout);

	enter();
	solve();

	return 0;
}
